# A shell program to search a file traversing recursively from the current directory
#Command: csh rfind.csh file_name
set fnd_flag = 1
if ($#argv != 1) then
	echo usage csh ~amba/tools/rfind.csh file
	exit(1)
endif
	set dirs = $cwd
        set file = $argv[1]
while ($#dirs > 0)
	set dir = $dirs[1]
        shift dirs

	foreach f ($dir/*)
		if ($f == $dir/$file) then
			echo file $file found in $dir
                        set fnd_flag= 0
		else if (-d $f)  then
			set dirs = ($f $dirs)
		endif
	end
end

if ($?fnd_flag) then
echo File $file not found
endif
