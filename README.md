# CmdProtocalParser (CPP)

This is the source code that is shown in [@endermanch](https://github.com/endermanch)'s video where he creates a custom protocol with little change.
You might be wondering, "Why did you copy down his code and release it on GitHub?". The answer is: I had nothing better to do and I might as well upload it
if anyone else needed it (which I doubt).

## Set Up Protocol

To set up the protocol, follow these steps:

Step 1: Open the Registry Editor.
Step 2: Then, create a new key in Computer\HKEY_CLASSES_ROOT named anything you want. In this case I'll call it 'cmd'.
Step 3: In the new key you created, create a new string called URL_Protocol.
Step 4: Change the value of (default) to 'URL:cmd Protocol'
Step 5: In the key you created, mines 'cmd', create another key named 'shell;
Step 6: In 'shell', create another key called 'open'
Step 7: In 'open', create another key called 'command'
Step 8: Before the next step, make sure you have downloaded or compiled the "CommandParser.exe" file and moved it to a safe place. In my case, I moved it to the C drive
Step 9: Finally, change (default) to '"{location}" "%1"'. Mine would look like: '"C:\CommandParser.exe" "%1"'

Congratulations! You've just created a protocol that runs the custom parser!

## Compiling

To compile the source code, run the following command in your terminal:

```bash
make