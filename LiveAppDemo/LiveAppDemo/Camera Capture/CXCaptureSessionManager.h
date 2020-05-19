//
//  CXCaptureSessionManager.h
//  LiveAppDemo
//
//  Created by chenxiao on 2020/5/18.
//  Copyright © 2020 com.kwai. All rights reserved.
//

#import <Foundation/Foundation.h>
@class AVCaptureVideoPreviewLayer;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(int, CXCaptureResolutionType) {
    CXCaptureResolutionTypeLow,
    CXCaptureResolutionTypeMedium,
    CXCaptureResolutionTypeHigh,

    CXCaptureResolutionType720p,
    CXCaptureResolutionType1080p
};

@interface CXCaptureSessionManager : NSObject
/// 用来预览,配置好以后layer就会被创建
@property (nonatomic, readonly) AVCaptureVideoPreviewLayer *videoLayer;

+ (instancetype)manager;

/// 默认使用前置摄像头
+ (void)requestCameraPermission:(void(^)(BOOL granted))callback;
- (void)setupSession;

- (void)startCapture;
- (void)stopCapture;

- (void)flipCameraToFront:(BOOL)captureFront;
- (void)changeResolution:(CXCaptureResolutionType)type;
- (void)changeFrameRate:(NSInteger)frameRate;

@end

NS_ASSUME_NONNULL_END
