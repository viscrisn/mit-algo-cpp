# menu program
echo menu test program
stop=0
while test $stop -eq 0
do
cat <<ENDOFMENU
1	: date
2,3	: pwd
4	: exit
ENDOFMENU
echo
echo 'Enter ur choice :- '
read ch
echo

case $ch in
"1")
date
;;
"2" | "3")
pwd
;;
"4")
stop=1
;;
*)
echo Illegal
;;

esac

done
