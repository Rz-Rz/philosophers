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
    sleep 5
    pkill $1
    output=$(grep died -m 1 "./log_$1" | awk '{print $NF}')
	count=$(grep -c died "./log_$1")
	grep -c died "./log_$1"
    if [ "$output" = "died" && count -eq 1];then
        echo "${green}[+] Test #1 Succeeded !${reset}"
    else
        echo "${red}[+] Test #1 Failed !${reset}"
        error_log $1 "Test #1" "Given 4 310 200 100 arguments to $1, a philosopher should die !"
    fi
    rm -rf "./log_$1"
}

test_two ()
{
    ("$2/$1" 1 800 200 200 > "./log_$1")&
    sleep 5
    pkill $1
    output=$(grep died -m 1 "./log_$1" | awk '{print $NF}')
	count=$(grep -c died "./log_$1")
	cat count;
    if [ "$output" = "died" && count -eq 1];then
        echo "${green}[+] Test #2 Succeeded !${reset}"
    else
        echo "${red}[+] Test #2 Failed !${reset}"
        error_log $1 "Test #2" "Given 1 800 200 200 arguments to $1, a philosopher should die !"
    fi
    rm -rf "./log_$1"
}

test_three ()
{
    ("$2/$1" 4 200 205 200 > "./log_$1")&
    sleep 5
    pkill $1
    output=$(grep died -m 1 "./log_$1" | awk '{print $NF}')
	count=$(grep -c died "./log_$1")
    if [ "$output" = "died" && count -eq 1];then
        echo "${green}[+] Test #3 Succeeded !${reset}"
    else
        echo "${red}[+] Test #3 Failed !${reset}"
        error_log $1 "Test #3" "Given 4 200 205 200 arguments to $1, a philosopher should die !"
    fi
    rm -rf "./log_$1"
}

test_four ()
{
    ("$2/$1" 4 310 60 400 > "./log_$1")&
    sleep 5
    pkill $1
    output=$(grep died -m 1 "./log_$1" | awk '{print $NF}')
	count=$(grep -c died "./log_$1")
    if [ "$output" = "died" && count -eq 1];then
        echo "${green}[+] Test #4 Succeeded !${reset}"
    else
        echo "${red}[+] Test #4 Failed !${reset}"
        error_log $1 "Test #4" "Given 4 310 60 400 arguments to $1, a philosopher should die !"
    fi
    rm -rf "./log_$1"
}


if [ "$2" -eq 1 -o "$2" -eq 0 ];then

    echo "[============[Testing philo]==============]\n"

    target="philo"
    make -C "$1/" > /dev/null

    if [ "$?" -ne 0 ];then
        echo "\n${red}[+] There's a problem while compiling $target, please recheck your inputs${reset}"
        exit
    fi

    test_one $target $1
    # test_two $target $1
    # test_three $target $1
    # test_four $target $1

    rm -rf "./log_$target"
fi

