#import <UIKit/UIKit.h>
#import "AccountsController.h"
#import "LoginController.h"
#import "ASINetworkQueue.h"


@class GHUser, GHOrganization;

@interface iOctocat : NSObject <UIApplicationDelegate, LoginControllerDelegate> {
  @private
    IBOutlet UIWindow *window;
	IBOutlet UINavigationController *accountsNavController;
	LoginController *loginController;
	NSMutableDictionary *users;
	NSMutableDictionary *organizations;
	NSDate *didBecomeActiveDate;
	BOOL launchDefault;
}

@property(nonatomic,retain)NSMutableDictionary *users;
@property(nonatomic,retain)NSMutableDictionary *organizations;
@property(nonatomic,retain)NSDate *didBecomeActiveDate;
@property(nonatomic,readonly)LoginController *loginController;

+ (ASINetworkQueue *)queue;
+ (iOctocat *)sharedInstance;
+ (NSDate *)parseDate:(NSString *)theString;
- (GHUser *)currentUser;
- (UIView *)currentView;
- (GHUser *)userWithLogin:(NSString *)theLogin;
- (GHOrganization *)organizationWithLogin:(NSString *)theLogin;
- (NSDate *)lastReadingDateForURL:(NSURL *)url;
- (void)setLastReadingDate:(NSDate *)date forURL:(NSURL *)url;
- (void)alert:(NSString *)theTitle with:(NSString *)theMessage;
- (NSString *)cachedGravatarPathForIdentifier:(NSString *)theString;
										 
@end

