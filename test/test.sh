red=`tput setaf 1`
green=`tput setaf 2`
yellow=`tput setaf 3`
reset=`tput sgr0`

if [ "$#" -ne 2 ]; then
    echo " ${yellow}Usage: start.sh <Project Folder> <Test Type>"
    echo -e "\tType 0: test philo, and philo_bonus"
    echo -e "\tType 1: test philo only"
    echo -e "\tType 2: test philo_bonus only${reset}"

    exit
fi

if [ "$2" -gt 2 -o "$2" -lt 0 ]; then
    echo "${Red}[Error]: Wrong Arguments${reset}"
    exit
fi

echo -e "${yellow}[+] Given Folder: $1"
echo -e "[+] Test Type: $2"
echo -e "[+] In Case of a failed test, please check ./errors_log file for more information${reset}\n"

error_log ()
{
    echo "[$1-$2]: $3" >> ./errors_log
}

test_one ()
{
    ("$2/$1" 4 310 200 100 > "./log_$1")&
    sleep 2
    pkill $1
    output=$(grep died -m 1 "./log_$1" | awk '{print $NF}')
	count=$(grep -c died "./log_$1")
	after_died=$(sed -n '/died/{n;p;}' "./log_$1")
	if [ "$output" = "died" ] && [ "$count" = "1" ];then
		# Extract all lines after the first occurrence of "died"
		after_died=$(sed -n '/died/{n;p;}' "./log_$1")
  		# Check if there are any more messages after "died"
  		if [ -n "$after_died" ]; then
	 		echo "${red}[-] Test #1 Failed: Simulation does not end after a death${reset}"
  		else
	 		echo "${green}[+] Test #1 Succeeded !${reset}"
  	fi
    else
		if [ "$count" = "0" ]; then
			echo "${red}[-] Test #1 Failed: No death${reset}"
		fi
		if [ "$count" > "1" ]; then
			echo "${red}[-] Test #1 Failed: More than one death${reset}"
		fi
        # error_log $1 "Test #1" "Given 4 310 200 100 arguments to $1, a philosopher should die !"
    fi
    rm -rf "./log_$1"
}

test_philosopher () {
  local program_name="$1"
  local program_path="$2"
  local program_params=("${@:3:4}")
  local test_number="$4"
  local log_file="./log_$program_name"
  ("$program_path/$program_name" "${program_params[@]}" > "$log_file")&
  sleep 2
  pkill "$program_name"

  check_death_occurred  "$test_number" "$log_file" || return 1
  check_simulation_ends "$test_number" "$log_file" || return 1

  # rm -rf "$log_file"
}

check_death_occurred () {
  local test_num="$1"
  local log_file="$2"
  local death_count=$(grep -c died "$log_file")

  if [ "$death_count" -eq 0 ]; then
    echo "${red}[-] Test #${test_num} Failed: No death${reset}"
    return 1
  elif [ "$death_count" -gt 1 ]; then
    echo "${red}[-] Test #${test_num} Failed: More than one death${reset}"
    return 1
  fi

  echo "${green}[+] Test #${test_num} Succeeded ! Only one death occured.${reset}"
}

check_simulation_ends () {
  local test_num="$1"
  local log_file="$2"
  local after_death=$(sed -n '/died/{n;p;}' "$log_file")

  if [ -n "$after_death" ]; then
    echo "${red}[-] Test #${test_num} Failed: Simulation does not end after a death${reset}"
    return 1
  fi

  echo "${green}[+] Test #${test_num} Succeeded ! Simulation ends after death${reset}"
}

if [ "$2" -eq 1 -o "$2" -eq 0 ];then

    echo -e "[============[Testing philo]==============]\n"

    target="philo"
    make -C "$1/" > /dev/null

    if [ "$?" -ne 0 ];then
        echo "\n${red}[+] There's a problem while compiling $target, please recheck your inputs${reset}"
        exit
    fi

    # test_one $target $1
	test_philosopher "$target" "$1" "4" "310" "200" "100" "2"
    # test_two $target $1
    # test_three $target $1
    # test_four $target $1

    # rm -rf "./log_$target"
fi

