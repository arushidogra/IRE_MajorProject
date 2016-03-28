#To search file xyz.abc starting from directory /usr the command will be
#fnd.sh /usr xyz.abc
#Wild card characters in file name can be used but 
# 1.They must be preceded by \ 
# 2.Command should be given in original form 
#For example : find /usr/cs/vc/temp -name lw\?\* -exec ls -l {} \;
find $1 -name $2 -exec ls -l {} \;
