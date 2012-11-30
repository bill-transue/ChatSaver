/*
 * messages.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class messagesItem, messagesApplication, messagesColor, messagesDocument, messagesWindow, messagesRichText, messagesCharacter, messagesParagraph, messagesWord, messagesAttributeRun, messagesAttachment, messagesApplication, messagesBuddy, messagesService, messagesChat, messagesTextChat, messagesAudioChat, messagesVideoChat, messagesAuthorizationRequest, messagesFileTransfer;

enum messagesSaveOptions {
	messagesSaveOptionsYes = 'yes ' /* Save the file. */,
	messagesSaveOptionsNo = 'no  ' /* Do not save the file. */,
	messagesSaveOptionsAsk = 'ask ' /* Ask the user whether or not to save the file. */
};
typedef enum messagesSaveOptions messagesSaveOptions;

enum messagesInviteType {
	messagesInviteTypeAudioInvitation = 'acon',
	messagesInviteTypeTextChatInvitation = 'tcon',
	messagesInviteTypeVideoInvitation = 'vcon'
};
typedef enum messagesInviteType messagesInviteType;

enum messagesAccountStatus {
	messagesAccountStatusAvailable = 'aval',
	messagesAccountStatusAway = 'away',
	messagesAccountStatusOffline = 'offl',
	messagesAccountStatusInvisible = 'invs',
	messagesAccountStatusIdle = 'idle',
	messagesAccountStatusUnknown = 'unkn'
};
typedef enum messagesAccountStatus messagesAccountStatus;

enum messagesMyStatus {
	messagesMyStatusAway = 'away',
	messagesMyStatusAvailable = 'aval',
	messagesMyStatusOffline = 'offl',
	messagesMyStatusInvisible = 'invs'
};
typedef enum messagesMyStatus messagesMyStatus;

enum messagesConnectionStatus {
	messagesConnectionStatusDisconnecting = 'dcng',
	messagesConnectionStatusConnected = 'conn',
	messagesConnectionStatusConnecting = 'cong',
	messagesConnectionStatusDisconnected = 'dcon'
};
typedef enum messagesConnectionStatus messagesConnectionStatus;

enum messagesCapabilities {
	messagesCapabilitiesVideoChat = 'vcon',
	messagesCapabilitiesAudioChat = 'acon',
	messagesCapabilitiesMultipersonVideo = 'mwvc',
	messagesCapabilitiesMultipersonAudio = 'mwac'
};
typedef enum messagesCapabilities messagesCapabilities;

enum messagesScreenSharing {
	messagesScreenSharingNone = 'ssns',
	messagesScreenSharingLocalScreen = 'ssls',
	messagesScreenSharingRemoteScreen = 'ssrs'
};
typedef enum messagesScreenSharing messagesScreenSharing;

enum messagesServiceType {
	messagesServiceTypeAIM = 'saim',
	messagesServiceTypeBonjour = 'ssub',
	messagesServiceTypeJabber = 'sjab',
	messagesServiceTypeIMessage = 'sims'
};
typedef enum messagesServiceType messagesServiceType;

enum messagesDirection {
	messagesDirectionIncoming = 'FTic',
	messagesDirectionOutgoing = 'FTog'
};
typedef enum messagesDirection messagesDirection;

enum messagesTransferStatus {
	messagesTransferStatusPreparing = 'FTsp',
	messagesTransferStatusWaiting = 'FTsw',
	messagesTransferStatusTransferring = 'FTsg',
	messagesTransferStatusFinalizing = 'FTsz',
	messagesTransferStatusFinished = 'FTsf',
	messagesTransferStatusFailed = 'FTse'
};
typedef enum messagesTransferStatus messagesTransferStatus;

enum messagesAvType {
	messagesAvTypeAudio = 'ICAa',
	messagesAvTypeVideo = 'ICAv'
};
typedef enum messagesAvType messagesAvType;

enum messagesChatType {
	messagesChatTypeInstantMessage = 'ICim',
	messagesChatTypeDirectInstantMessage = 'ICdi',
	messagesChatTypeChatRoom = 'ICcr'
};
typedef enum messagesChatType messagesChatType;

enum messagesJoinState {
	messagesJoinStateNotJoined = 'ICJc',
	messagesJoinStateJoining = 'ICJg',
	messagesJoinStateJoined = 'ICJj'
};
typedef enum messagesJoinState messagesJoinState;

enum messagesAvConnectionStatus {
	messagesAvConnectionStatusInvited = 'ICAi',
	messagesAvConnectionStatusWaiting = 'ICAw',
	messagesAvConnectionStatusConnecting = 'ICAx',
	messagesAvConnectionStatusConnected = 'ICAc',
	messagesAvConnectionStatusEnded = 'ICAn'
};
typedef enum messagesAvConnectionStatus messagesAvConnectionStatus;



/*
 * Standard Suite
 */

// A scriptable object.
@interface messagesItem : SBObject

@property (copy) NSDictionary *properties;  // All of the object's properties.

- (void) closeSaving:(messagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// The application's top-level scripting object.
@interface messagesApplication : SBApplication

- (SBElementArray *) documents;
- (SBElementArray *) windows;

@property (copy, readonly) NSString *name;  // The name of the application.
@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *version;  // The version of the application.

- (void) open:(NSArray *)x;  // Open a document.
- (void) print:(NSURL *)x;  // Print an object.
- (void) quitSaving:(messagesSaveOptions)saving;  // Quit the application.
- (void) invite:(NSArray *)x to:(id)to withMessage:(NSString *)withMessage;  // Invites a buddy to join an existing chat.
- (void) logIn;  // Log in to the specified service, or all services if none is specified. If the account password is not in the keychain the user will be prompted to enter one.
- (void) logOut;  // Logs out of a service, or all services if none is specified.
- (void) send:(id)x to:(id)to;  // Sends a message or file to a buddy or to a chat.
- (void) storeRecentPicture;  // Stores the currently set buddy picture into your recent pictures.
- (void) showChatChooserFor:(messagesBuddy *)for_;  // displays a dialog in Messages to start a new chat with the specified buddy

@end

// A color.
@interface messagesColor : SBObject

- (void) closeSaving:(messagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// An Messages document.
@interface messagesDocument : SBObject

@property (copy, readonly) NSString *name;  // The document's name.
@property (readonly) BOOL modified;  // Has the document been modified since the last save?
@property (copy, readonly) NSURL *file;  // The document's location on disk.

- (void) closeSaving:(messagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// A window.
@interface messagesWindow : SBObject

@property (copy, readonly) NSString *name;  // The full title of the window.
- (NSInteger) id;  // The unique identifier of the window.
@property NSInteger index;  // The index of the window, ordered front to back.
@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Whether the window has a close box.
@property (readonly) BOOL minimizable;  // Whether the window can be minimized.
@property BOOL minimized;  // Whether the window is currently minimized.
@property (readonly) BOOL resizable;  // Whether the window can be resized.
@property BOOL visible;  // Whether the window is currently visible.
@property (readonly) BOOL zoomable;  // Whether the window can be zoomed.
@property BOOL zoomed;  // Whether the window is currently zoomed.
@property (copy, readonly) messagesDocument *document;  // The document whose contents are being displayed in the window.

- (void) closeSaving:(messagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end



/*
 * Text Suite
 */

// Rich (styled) text
@interface messagesRichText : SBObject

- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) attachments;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property double size;  // The size in points of the first character.

- (void) closeSaving:(messagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// This subdivides the text into characters.
@interface messagesCharacter : SBObject

- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) attachments;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.

- (void) closeSaving:(messagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// This subdivides the text into paragraphs.
@interface messagesParagraph : SBObject

- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) attachments;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.

- (void) closeSaving:(messagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// This subdivides the text into words.
@interface messagesWord : SBObject

- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) attachments;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.

- (void) closeSaving:(messagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// This subdivides the text into chunks that all have the same attributes.
@interface messagesAttributeRun : SBObject

- (SBElementArray *) characters;
- (SBElementArray *) paragraphs;
- (SBElementArray *) words;
- (SBElementArray *) attributeRuns;
- (SBElementArray *) attachments;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.

- (void) closeSaving:(messagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.

@end

// Represents an inline text attachment. This class is used mainly for make commands.
@interface messagesAttachment : messagesRichText

@property (copy, readonly) NSURL *file;  // The path to the file for the attachment


@end



/*
 * Messages Suite
 */

// Messages application.
@interface messagesApplication (MessagesSuite)

- (SBElementArray *) buddies;
- (SBElementArray *) services;
- (SBElementArray *) fileTransfers;
- (SBElementArray *) chats;
- (SBElementArray *) textChats;
- (SBElementArray *) audioChats;
- (SBElementArray *) videoChats;
- (SBElementArray *) authorizationRequests;

@property (readonly) NSInteger idleTime;  // Time in seconds that I have been idle.
@property (copy) NSImage *image;  // My image as it appears in all services.
@property messagesMyStatus status;  // My status on all services.
@property (copy) NSString *statusMessage;  // My status message, visible to other people while I am online.
@property (copy) messagesAudioChat *activeAvChat;  // The currently active audio or video chat.

@end

// A buddy on a service.
@interface messagesBuddy : messagesItem

- (NSString *) id;  // The buddy's service and handle. For example: AIM:JohnDoe007
@property (copy, readonly) messagesService *service;  // The service on which this buddy exists.
@property (copy, readonly) NSString *name;  // The buddy's name as it appears in the buddy list.
@property (copy, readonly) NSString *handle;  // The buddy's online account name.
@property (readonly) messagesAccountStatus status;  // The buddy's current status.
@property (copy, readonly) NSString *statusMessage;  // The buddy's current status message.
@property (readonly) NSInteger idleTime;  // The time in seconds the buddy has been idle.
@property (copy, readonly) NSArray *capabilities;  // The buddy's messaging capabilities.
@property (copy, readonly) NSImage *image;  // The buddy's custom image.
@property (copy, readonly) NSString *firstName;  // The first name from this buddy's Contacts card, if available
@property (copy, readonly) NSString *lastName;  // The last name from this buddy's Contacts card, if available
@property (copy, readonly) NSString *fullName;  // The full name from this buddy's Contacts card, if available


@end

// A service that can be logged in from this system
@interface messagesService : messagesItem

- (SBElementArray *) buddies;
- (SBElementArray *) chats;

- (NSString *) id;  // A guid identifier for this service.
@property (copy) NSString *name;  // The name of this service as defined in Account preferences description field
@property BOOL enabled;  // Is the service enabled?
@property (readonly) messagesConnectionStatus connectionStatus;  // The connection status for this account.
@property messagesMyStatus status;  // My status on this service.
@property (copy) NSString *statusMessage;  // My status message, visible to other people on this service while I am online.
@property (readonly) messagesServiceType serviceType;  // The type of protocol for this service

- (void) logIn;  // Log in to the specified service, or all services if none is specified. If the account password is not in the keychain the user will be prompted to enter one.
- (void) logOut;  // Logs out of a service, or all services if none is specified.

@end

// An audio, video, or text chat.
@interface messagesChat : SBObject

- (NSString *) id;  // A guid identifier for this chat.
@property (copy, readonly) messagesService *service;  // The service which is participating in this chat.
@property (copy, readonly) NSArray *participants;  // Other participants of this chat. This property may be specified at time of creation.
@property (readonly) BOOL secure;  // Is this chat secure?
@property (readonly) BOOL invitation;  // Is this an invitation to a chat?
@property (readonly) BOOL active;  // Is this chat currently active?
@property (copy, readonly) NSDate *started;  // The date on which this chat started.
@property (copy, readonly) NSDate *updated;  // The date when this chat was last updated.

- (void) closeSaving:(messagesSaveOptions)saving savingIn:(NSURL *)savingIn;  // Close a document.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save a document.
- (void) delete;  // Delete an object.
- (SBObject *) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (SBObject *) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) accept;  // Accepts an incoming text, audio, or video chat invitation, or file transfer
- (void) decline;  // Declines an incoming text, audio, or video chat invitation, or file transfer

@end

// A text chat.
@interface messagesTextChat : messagesChat

@property (copy, readonly) NSString *subject;  // The subject of this chat, if available.
@property (copy, readonly) NSString *invitationMessage;  // An invitation message. This may only be specified at the time of creation. This message will be sent to chat participants when the chat is created.
@property (readonly) messagesJoinState joinState;  // How you are joined to this chat
@property (copy, readonly) NSString *name;  // The address or room name of this chat. This property may be specified at time of creation.
@property (readonly) messagesChatType chatType;  // The type of this chat.


@end

// An audio or video chat.
@interface messagesAudioChat : messagesChat

@property (readonly) messagesScreenSharing screenSharing;  // Type of screen sharing session taking place within this chat.
@property BOOL muted;  // Is the chat muted?
@property (readonly) messagesAvConnectionStatus avConnectionStatus;  // The connection state for this av chat.

- (void) requestRecording;  // Sends a recording request to all participants of an audio or video chat. Recording will not start until all participants have agreed to allow recording.
- (void) stopRecording;  // Ends recording of an audio or video chat.

@end

@interface messagesVideoChat : messagesAudioChat

@property BOOL paused;  // Is the chat paused?
@property BOOL showingFullScreen;  // Is the chat being displayed in full screen mode?
@property BOOL showingLocalVideo;  // Is the local video preview being displayed?

- (void) takeSnapshot;  // Takes a snapshot of a video chat and saves it to a desktop.

@end

// A request to be added to someone else's buddy list
@interface messagesAuthorizationRequest : messagesItem

- (NSString *) id;  // The guid for this authorization request
@property (copy, readonly) messagesService *service;  // The service on which authorization was requested.
@property (copy, readonly) messagesBuddy *buddy;  // The buddy requesting authorization


@end

// A file being sent or received
@interface messagesFileTransfer : messagesItem

- (NSString *) id;  // The guid for this file transfer
@property (copy, readonly) NSString *name;  // The name of this file
@property (copy, readonly) NSURL *file;  // The local path to this file transfer
@property (readonly) messagesDirection direction;  // The direction in which this file is being sent
@property (copy, readonly) messagesService *service;  // The service on which this file transfer is taking place
@property (copy, readonly) messagesBuddy *buddy;  // The account participating in this file transfer
@property (readonly) BOOL secure;  // Is this file transfer secure?
@property (readonly) NSInteger fileSize;  // The total size in bytes of the completed file transfer
@property (readonly) NSInteger fileProgress;  // The number of bytes that have been transferred
@property (readonly) messagesTransferStatus transferStatus;  // The current status of this file transfer
@property (copy, readonly) NSDate *started;  // The date that this file transfer started

- (void) accept;  // Accepts an incoming text, audio, or video chat invitation, or file transfer
- (void) decline;  // Declines an incoming text, audio, or video chat invitation, or file transfer

@end

