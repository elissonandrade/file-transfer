# file-transfer

# This program transfer files from one directory to
# another following parameters configured in a .cfg file.
# To run this program correctily, you must compile, configure
# and only then execute it. This program also has multiple
# unit test to check individual funcionalities of the code.

###############
# Compilation #
###############

# There is a Makefile in the root of this project.
# To compile the main program, simple run the comand

	make

# Running this command will create a executable named
# "transfer" at the 'bin' directory
# To compile the unit tests, use the command

	make testName

# where 'testName' can be each one of the filenames 
# in the 'test' directory, with the .cpp extension
# The compilation of the unit tests will generate
# executable of the same name as the test at the 'bin'
# directory. Each executable is completely independent
# of each other

#################
# Configuration #
#################

# By default, the "transfer" executable reads from a configuration
# file named "transfer.cfg" in the same directory where it is executed.
# A example of "transfer.cfg" file is provided at the "bin" directory.
# There are 5 parameter that can be configured at the "transfer.cfg" file:
# "origin" is the path to the directory where files will be searched
# "destiny" is the path to the directory where files will be moved
# "pattern" is the regular expression that will be used to select the files
# to transfer by name. Uses the ECMAScript model of regular expressions
# "period" is the value in seconds of the interval in which files will be
# searched and transferred
# "recentFirst" when set with the value "y", will guarantee that only the
# most recent file that matcher the pattern will be tranferred after each
# period passing when set with any other value, all files that match the
# pattern will be tranferred at once

# You can use a different config file by typing the path to it as argument
# of the program, like this:

	./transfer path/to/config/file.cfg

###########
# Running #
###########

# After setting up the config file and compiling the program, the program
# can be executed from anywhere on the local filesystem.

	./transfer

#All the paths on the config file will be relative to the local where the
# program is executed. The values in the config file can be changed even
# after the program is running. The program will output messages telling
# which files are being transferred at any given time.

# To run the unit test correctly, the usser must have all the permissions
# to create files and subdirectory where the tests will be executed
