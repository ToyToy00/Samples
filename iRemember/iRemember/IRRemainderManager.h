//
//  IRRemainderManager.h
//  iRemember
//
//  Created by Danis Tazetdinov on 04.03.13.
//  Copyright (c) 2013 Demo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <EventKit/EventKit.h>

extern NSString * const IRRemainderManagerAccessGrantedNotification;

typedef void (^IRRemainderFetchCompletionBlock)(NSArray *remainders);

@interface IRRemainderManager : NSObject

// Access to remainders

@property (atomic, readonly) BOOL accessGranted;
-(void)requestAccess;

// Verification methods

+(BOOL)isCalendarIdentifierValid:(NSString*)calendarIdentifier;

// Fetch and add remainders

-(void)fetchRemaindersInCalendarWithIdentifier:(NSString*)identifier completion:(IRRemainderFetchCompletionBlock)completionBlock;
-(EKReminder*)addRemainderWithTitle:(NSString*)title inCalendarWithIdentifier:(NSString*)calendarIdentifier;

// Sources, calendars

-(NSArray*)sources;
-(NSArray*)remainderCalendars;
-(EKCalendar*)addCalendarWithTitle:(NSString*)title inSourceWithIdentifier:(NSString*)sourceIdentifier;

@end