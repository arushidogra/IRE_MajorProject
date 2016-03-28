require "subst.pl";

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
	   if(( $_ !~ /\.o$/) && ($_ !~ /\.out$/) && ($_ !~ /\.z$/)) {
	&subst($_);
   }
   }
   }
else {
  $subcount = $nlink - 2;
	for(@filenames) {
	   next if $_ eq '.';
	   next if $_ eq '..';
	   $name = "$dir/$_";
	($dev,$ino,$mode,$nlink) = lstat($_);
	   if((! -d _) && ( $_ !~ /\.o$/) && ($_ !~ /\.out$/) && ( $_ !~ /\.z$/)) {
		&subst($_);
	    }
	next if $subcount == 0;

	next unless -d _;

	chdir $_ || die " Can't cd to $name";
	print STDERR " cd to $name\n";
	&dodir($name,$nlink);
	chdir '..';
	--$subcount;
	}
}
}
