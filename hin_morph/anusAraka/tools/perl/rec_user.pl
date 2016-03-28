# This program recursively descends thro' all the subdirectories and performs the user defined action on the files in them.
# absolute path of the file containing user defined action is passed as a command line argument.
# Name of the subroutine is assumed to be 'desired_action'
# usage /1d1/amba/ttools/shell_files/rec_user.pl file_name
require "$ARGV[0]";

&dodir('.');

sub dodir{
	local($dir,$nlink) = @_;
	local($dev,$ino,$mode,$subcount);

($dev,$ino,$mode,$nlink) = stat('.') unless $nlink;
opendir(DIR,'.') || die " Can't open $dir";
local(@filenames) = readdir(DIR);
closedir(DIR);


if($nlink == 2) {
   for (@filenames) {
	next if $_ eq '.';
	next if $_ eq '..';
# User defined function starts here
	&desired_action($_);
# User defined function ends

   }
}
else {
  $subcount = $nlink - 2;
	for(@filenames) {
	   next if $_ eq '.';
	   next if $_ eq '..';
	   $name = "$dir/$_";
	next if $subcount == 0;

	($dev,$ino,$mode,$nlink) = lstat($_);
# User defined function starts here
	&desired_action($_);
# User defined function ends
	next unless -d _;
	chdir $_ || die " Can't cd to $name";
	&dodir($name,$nlink);
	chdir '..';
	--$subcount;
	}
   }
}
