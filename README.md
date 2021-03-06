# rshell

## Overview

This repository contains a c++ program that mimics a simple command shell called **rshell**. It is able to execute programs within `/bin/`. Additonally, it is able to execute test commands. 
The simple shell also uses connectors to string commands together.

The avaliable connectors are the following: `&&`, `||`, and `;`.

The rshell works with the following input format
    
    command = executable [ argumentList ] [ connector cmd ]
    connector = && or || or ;

Example: 

    ls -la && date; echo Done!

There are are total of three executables in the example; `ls`, `date`, and `echo`.
the ls command will list the files in the working directory. The arugment list for ls
is `l` and `a`. The `l` argument will print the output in a long listing format. While
the `a` argument will print all files in the working directory such as invisible files.

The `date` command will print the current date. And the `echo` command will print out its argument
which in this case is the string `Done!`.

The connector `&&` acts as an AND. If the exectable to the left of `&&` executes correctly then
the executable to the right of the connector will also execute regardless if it executes correctly
or not. For the `||` connector the executable to the right of it will only execute if the exectuable
before the connector fails. Lastly the `;` connector acts as a breakpoint. Any of the executables 
will run regardless of its status.

The command test can be used to check if a file or directory exist. The command will output either 
`(True)` or `(False)` in regards to whether it exist. The following are example formats to the `test` command.

    test main.cpp
    [ main.cpp ]
    [ -d directory/ ]
    test -e directory/file

The `test` command has the following arguments: `-e`, `-d` and `-f`. The `-e` argument is used by defualt when
there is no argument provided. The argument tells test to check wheter the file/directory exist. The `-d` argument
tells test to check if the file/directory that user inputs is a directory. While `-f` checks if the specificed file/directory is a regular file.

Notice the example, `[ main.cpp ]`, The brackets act as an alias to test. In order for the alias to work it has to have the opening bracket `[` and the closing bracket `]`.

The use of `( )` gives a specified command(s) priority to its overall return truth value. The `( )` does not give priority in the sense of displaying its result, but rather it groups the overall return value of mutliple commands.

## New

New in **rshell** is the cd command. The cd command will change the current working directory to whatever directory is specified. There are three uses of this command
    cd <PATH>
    cd
    cd -

cd <PATH> changes the working directory to the directory specified in path.
cd changes the working directory to the users HOME directory
cd - changes the working directory to the previous working directory
cd .. can be used to to go up a level in the working directory

## Bugs

In the following:

    echo "#sup"

the output should be `#sup` ( in the normal shell ), but instead it displays `'`. The reason for this, is that the rshell
ignores everything after the `#` comment symbol, so only the first qoutation mark outputs on the screen


In the following input:

    ls && #pw
    ls || #pwd

In the previous version of **rshell** the result of the input will go into an input mode.
Now, we ignore that and just display the command.

(Not a bug )The use of `/` to indicate location of a file or directory has to be used correctly with the use of test.
For example

    test /dev

works correctly and properly at any current working directory as long as file/directory is not in the c.w.d.. While in the other hand using 
    
    test /dir

in which dir is inside the current working directory is improper use of `/`

 
