case $1 in "add")
case $2 in "read")
chmod +r $3
;;
"write")
chmod +w $3
;;
"execute")
chmod +x $3
;;
esac
;;
"remove")
case $2 in "read")
chmod -r $3
;;
"write")
chmod -w $3
;;
"execute")
chmod -x $3
;;
esac
;;
esac
