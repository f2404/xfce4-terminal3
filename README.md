# xfce4-terminal3
This is an attempt to port [xfce4-terminal](http://docs.xfce.org/apps/terminal/start) to gtk3/vte3.

The main reason for the porting is this [issue](https://github.com/MidnightCommander/mc/issues/103)
which makes midnight commander unusable with the current version of the terminal.

## Status
The application is building AND running! There are 2 obvious issues now: the default geometry is not
applied, and the preferences dialog is unusable. However, mc is running fine :)
