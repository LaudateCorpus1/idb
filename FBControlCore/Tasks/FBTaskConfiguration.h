/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <Foundation/Foundation.h>

#import <FBControlCore/FBProcessLaunchConfiguration.h>

NS_ASSUME_NONNULL_BEGIN

@class FBProcessIO;

@protocol FBControlCoreLogger;

/**
 A Configuration for an FBTask.
 */
@interface FBTaskConfiguration : FBProcessLaunchConfiguration

/**
 Creates a Task Configuration with the provided parameters.
 */
- (instancetype)initWithLaunchPath:(NSString *)launchPath arguments:(NSArray<NSString *> *)arguments environment:(NSDictionary<NSString *, NSString *> *)environment acceptableExitCodes:(nullable NSSet<NSNumber *> *)acceptableExitCodes io:(FBProcessIO *)io logger:(nullable id<FBControlCoreLogger>)logger programName:(NSString *)programName;

/**
 The Launch Path of the Process to launch.
 */
@property (nonatomic, copy, readonly) NSString *launchPath;

/**
 The exit codes that are permitted for the launched process to indicate.
 Any other exit code, including signals are considered erroneous.
 A nil value indicates that this check will not occur.
 */
@property (nonatomic, copy, nullable, readonly) NSSet<NSNumber *> *acceptableExitCodes;

/**
 The logger to log to.
 */
@property (nonatomic, strong, nullable, readonly) id<FBControlCoreLogger> logger;

/**
 The program display name for logging.
 */
@property (nonatomic, copy, readonly) NSString *programName;

@end

NS_ASSUME_NONNULL_END
