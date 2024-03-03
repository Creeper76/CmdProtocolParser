# CmdProtocalParser (CPP)

Before I start, I want to make it very clear that I didn't make this. [@endermanch](https://github.com/endermanch) made it! Check out his youtube if you like techy
things!

This is the source code that is shown in [@endermanch](https://github.com/endermanch)'s video where he creates a custom protocol with little change.
You might be wondering, "Why did you copy down his code and release it on GitHub?". The answer is: I had nothing better to do and I might as well upload it
if anyone else needed it (which I doubt).

## Set Up Protocol

To set up the protocol, follow these steps:

1. Open the Registry Editor.
2. Then, create a new key in Computer\HKEY_CLASSES_ROOT named anything you want. In this case I'll call it 'cmd'.
3. In the new key you created, create a new string called URL_Protocol.
4. Change the value of (default) to 'URL:cmd Protocol'.
5. In the key you created, mine's 'cmd', create another key named 'shell'.
6. In 'shell', create another key called 'open'.
7. In 'open', create another key called 'command'.
8. Before the next step, make sure you have downloaded or compiled the "CommandParser.exe" file and moved it to a safe place. In my case, I moved it to the C drive.
9. Finally, change (default) to '"{location}" "%1"'. Mine would look like: '"C:\CommandParser.exe" "%1"'.

Congratulations! You've just created a protocol that runs the custom parser!

## Compiling

To compile the source code, run the following command in your terminal:

```bash
make