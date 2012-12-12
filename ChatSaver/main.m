//
//  main.m
//  ChatSaver
//
//  Created by Bill Transue on 11/30/12.
//  Copyright (c) 2012 Bill Transue. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "ChatSaver.h"

int main(int argc, char *argv[])
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    ChatSaver *obj = [[ChatSaver alloc] init];
    
    NSDate *now = [[NSDate alloc] init];
    NSTimer *timer = [[NSTimer alloc] initWithFireDate:now
                                              interval:.01
                                                target:obj
                                              selector:@selector(startIt)
                                              userInfo:nil
                                               repeats:YES];
    
    NSRunLoop *runLoop = [NSRunLoop currentRunLoop];
    [runLoop addTimer:timer forMode:NSDefaultRunLoopMode];
    [runLoop run];
    
    [pool release];
    return 0;
}