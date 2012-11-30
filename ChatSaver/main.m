//
//  main.m
//  ChatSaver
//
//  Created by Bill Transue on 11/30/12.
//  Copyright (c) 2012 Bill Transue. All rights reserved.
//

#import <Cocoa/Cocoa.h>

#import <AppleScriptObjC/AppleScriptObjC.h>

int main(int argc, char *argv[])
{
    [[NSBundle mainBundle] loadAppleScriptObjectiveCScripts];
    return NSApplicationMain(argc, (const char **)argv);
}