//
//  ViewController.h
//  Jetpac Deep Belief Learner
//
//  Created by Dave Fearon on 4/10/14.
//  Copyright (c) 2014 Jetpac. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>
#import "CustomButton.h"
@class CIDetector;

@interface ViewController : UIViewController <UIGestureRecognizerDelegate, AVCaptureVideoDataOutputSampleBufferDelegate>
{
    BOOL detectFaces;
	CIDetector *faceDetector;
    UIImage *square;
	BOOL isUsingFrontFacingCamera;
	CGFloat beginGestureScale;
	CGFloat effectiveScale;
    
    IBOutlet UIView *previewView;
	IBOutlet UISegmentedControl *camerasControl;
	AVCaptureVideoPreviewLayer *previewLayer;
	AVCaptureVideoDataOutput *videoDataOutput;
    dispatch_queue_t videoDataOutputQueue;
	AVCaptureStillImageOutput *stillImageOutput;
	UIView *flashView;
    UIImage *screenshot;
    CustomButton *actionButton;
    
    void* network;
    AVSpeechSynthesizer *synth;
    NSMutableDictionary* oldPredictionValues;
    NSMutableArray* labelLayers;
    AVCaptureSession* session;
    UIView *gradientLayer;
    
    NSString *iphoneModel;
    
    int positivePredictionsCount;
    int negativePredictionsCount;
    void* trainer;
    void* predictor;
    int predictionState;
    
    NSString* lastInfo;
    float timeToNextPing;
}

@property (retain, nonatomic) CATextLayer *predictionTextLayer;
@property (retain, nonatomic) CATextLayer *progressBackground;
@property (retain, nonatomic) CATextLayer *progressForeground;
@property (retain, nonatomic) CATextLayer *infoBackground;
@property (retain, nonatomic) CATextLayer *infoForeground;

@property (readwrite)   CFURLRef        soundFileURLRef;
@property (readonly)    SystemSoundID   soundFileObject;
@property (retain, nonatomic) NSDate *lastFrameTime;

@property (weak, nonatomic) IBOutlet UIButton *saveImage;

- (IBAction)takePicture:(id)sender;
- (IBAction)switchCameras:(id)sender;
- (IBAction)handlePinchGesture:(UIGestureRecognizer *)sender;
- (IBAction)toggleFaceDetection:(id)sender;

- (void)writeImageCompletion:(UIImage *)image didFinishSavingWithError:(NSError *)error contextInfo:(void *)contextInfo;

@end
