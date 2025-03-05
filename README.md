# Owner: Caio Lauro de Lima

Command-line tools for Fedora/Linux.

## Installation
You can use `make` to create the binary file `cll-tools` and execute it with `./cll-tools` or, alternatively,
use `sudo make install` to install automatically the binary file into `/usr/local/bin/cll-tools`.
You may also execute `make install prefix=/PATH` to install `cll-tools` in `PATH/bin/cll-tools`.

## Return codes
Any return code that differs from zero means a failure of some kind. The program has the following error return codes: 
1. Command not found.
2. Command not yet created in switch case of runCommand.\\
Since commands such as `update-system` use other software, they may return the same results, but with other meanings, just check the output to know what happened.
