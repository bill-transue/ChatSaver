--
--  ChatSaverAppDelegate.applescript
--  ChatSaver
--
--  Created by Bill Transue on 11/30/12.
--  Copyright (c) 2012 Bill Transue. All rights reserved.
--

script LogOn
    if application "Messages" is running then
        tell application "Messages"
            log in service "transue@gmail.com"
            set status of service "transue@gmail.com" to available
            set status message to "%Track - %Artist"
        end tell
    end if
end script

script LogOff
    if application "Messages" is running then
        tell application "Messages"
            log out
        end tell
    end if
end script