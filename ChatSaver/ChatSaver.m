//
//  ChatSaver.m
//  ChatSaver
//
//  Created by Bill Transue on 11/30/12.
//  Copyright (c) 2012 Bill Transue. All rights reserved.
//

#import "ChatSaver.h"
#import "messages.h"

@implementation ChatSaver

messagesApplication *messages;

-(void)awakeFromNib
{
    messages = [SBApplication applicationWithBundleIdentifier:@"com.apple.Messages"];
    [[NSDistributedNotificationCenter defaultCenter] addObserver:self
                                                        selector:@selector(screenSaverStarted:)
                                                            name:@"com.apple.screensaver.didstart"
                                                          object:nil];
    
    [[NSDistributedNotificationCenter defaultCenter] addObserver:self
                                                        selector:@selector(screenSaverStopped:)
                                                            name:@"com.apple.screensaver.didstop"
                                                          object:nil];
}

-(void)dealloc
{
    [[NSDistributedNotificationCenter defaultCenter] removeObserver:self];
    [super dealloc];
}

-(void)screenSaverStarted:(NSNotification *)notification
{
    if ( [messages isRunning] ) {
        [messages logIn];
    }
}

-(void)screenSaverStopped:(NSNotification *)notification
{
    if ( [messages isRunning] ) {
        [messages logOut];
    }
    
}
@end
