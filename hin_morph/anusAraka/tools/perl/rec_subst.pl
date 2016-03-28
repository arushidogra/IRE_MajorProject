# This program recursively descends thro' all the subdirectories and performs the user defined action on the files in them.
# Follwoing line contains the path of the file containing user defined action.
require "/1d1/amba/wip1/subst.pl";

&dodir('.');

sub dodir{
	local($dir,$nlink) = @_;
	local($dev,$ino,$mode,$subcount);

($dev,$ino,$mode,$nlink) = stat('.') unless $nlink;
#print STDERR $dir,"\n";
opendir(DIR,'.') || die " Can't open $dir";
local(@filenames) = readdir(DIR);
closedir(DIR);


if($nlink == 2) {
   for (@filenames) {
	next if $_ eq '.';
	next if $_ eq '..';
	#print "1 $dir/$_\n";
	($dev,$ino,$mode,$nlink) = stat($_);
# User defined function starts here
	   if(( $_ !~ /\.o$/) && ($_ !~ /\.out$/) && ($_ !~ /\.z$/)) {
	&subst($_);
   }
# User defined function ends
   }
   }
else {
  $subcount = $nlink - 2;
	for(@filenames) {
	   next if $_ eq '.';
	   next if $_ eq '..';
	   $name = "$dir/$_";
	($dev,$ino,$mode,$nlink) = lstat($_);
# User defined function starts here
	   if((! -d _) && ( $_ !~ /\.o$/) && ($_ !~ /\.out$/) && ( $_ !~ /\.z$/)) {
		&subst($_);
	    }
# User defined function ends
	next if $subcount == 0;

	next unless -d _;

	#chdir $_ || die " Can't cd to $name";
# Die is changed to print , as die will exit from the program. In case we want to continue in spite of error, print will report the error & continue .
	if(chdir $_ )
		{
		print STDERR " cd to $name\n";
		&dodir($name,$nlink);
		chdir '..';
		}
	else { print " Can't cd to $name";}
	--$subcount;
	}
}
}
