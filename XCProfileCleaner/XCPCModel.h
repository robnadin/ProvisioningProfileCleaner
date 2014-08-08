////  XCPRModel.h//  XToDo / XCPullRequest////  Created by Travis on 13-11-28.//  updated and modified by Kevin Bradley//  Copyright (c) 2013年 Plumn LLC. All rights reserved.//#import <Foundation/Foundation.h>#import <AppKit/AppKit.h>#import "XCPCProjectSetting.h"@interface XCPropertyInfoContext : NSObject- (id)expandedValueForString:(id)arg1 withConditionSet:(id)arg2;- (id)expandedValueForString:(id)arg1;- (id)expandedValueForPropertyNamed:(id)arg1;- (id)expandedValueForPropertyNamed:(id)arg1 withConditionSet:(id)arg2;- (void)setValue:(id)arg1 forPropertyName:(id)arg2;- (void)setValue:(id)arg1 forPropertyName:(id)arg2 conditionSet:(id)arg3;- (void)setValue:(id)arg1 forPropertyName:(id)arg2 conditionSet:(id)arg3 atDefinitionLevel:(int)arg4;@end@interface DVTMacroDefinitionConditionSet : NSObject+ (id)conditionSetFromStringRepresentation:(id)arg1 getBaseMacroName:(id *)arg2 error:(id *)arg3;@end@interface PBXObject : NSObject- (id)name;- (id)targetWithGlobalID:(id)arg1;- (id)targetNamed:(id)arg1;- (id)targets;- (id)targetTemplates;@end@interface PBXContainer : PBXObject@end@interface PBXProject : PBXContainer+ (id)projectWithFile:(id)arg1;- (id)cachedPropertyInfoContextForConfigurationNamed:(id)arg1;@end@interface DVTChoice : NSObject- (id)initWithTitle:(id)arg1 toolTip:(id)arg2 image:(id)arg3 representedObject:(id)arg4;@end@interface DVTTextDocumentLocation : NSObject@property (readonly) NSRange characterRange;@property (readonly) NSRange lineRange;@end@interface DVTTextPreferences : NSObject+ (id)preferences;@property BOOL trimWhitespaceOnlyLines;@property BOOL trimTrailingWhitespace;@property BOOL useSyntaxAwareIndenting;@end@interface DVTSourceTextStorage : NSTextStorage- (void)replaceCharactersInRange:(NSRange)range withString:(NSString *)string withUndoManager:(id)undoManager;- (NSRange)lineRangeForCharacterRange:(NSRange)range;- (NSRange)characterRangeForLineRange:(NSRange)range;- (void)indentCharacterRange:(NSRange)range undoManager:(id)undoManager;@end@interface DVTFileDataType : NSObject@property (readonly) NSString *identifier;@end@interface DVTFilePath : NSObject@property (readonly) NSURL *fileURL;@property (readonly) DVTFileDataType *fileDataTypePresumed;@end@interface IDEContainerItem : NSObject@property (readonly) DVTFilePath *resolvedFilePath;@end@interface IDEGroup : IDEContainerItem@end@interface IDEFileReference : IDEContainerItem@end@interface IDENavigableItem : NSObject@property (readonly) IDENavigableItem *parentItem;@property (readonly) id representedObject;@end@interface IDEFileNavigableItem : IDENavigableItem@property (readonly) DVTFileDataType *documentType;@property (readonly) NSURL *fileURL;@end@interface IDEStructureNavigator : NSObject@property (retain) NSArray *selectedObjects;@end@interface IDENavigableItemCoordinator : NSObject- (id)structureNavigableItemForDocumentURL:(id)arg1 inWorkspace:(id)arg2 error:(id *)arg3;@end@interface IDENavigatorArea : NSObject@property NSArrayController *extensionsController;- (id)currentNavigator;@end@interface IDEWorkspaceTabController : NSObject@property (readonly) IDENavigatorArea *navigatorArea;@property(readonly) IDEWorkspaceTabController *structureEditWorkspaceTabController;@end@interface IDEDocumentController : NSDocumentController+(IDEDocumentController*)sharedDocumentController;+ (id)editorDocumentForNavigableItem:(id)arg1;+ (id)retainedEditorDocumentForNavigableItem:(id)arg1 error:(id *)arg2;+ (void)releaseEditorDocument:(id)arg1;@end@interface IDESourceCodeDocument : NSDocument- (DVTSourceTextStorage *)textStorage;- (NSUndoManager *)undoManager;@end@interface IDESourceCodeComparisonEditor : NSObject@property (readonly) NSTextView *keyTextView;@property (retain) NSDocument *primaryDocument;@end@interface IDESourceCodeEditor : NSObject@property (retain) NSTextView *textView;- (IDESourceCodeDocument *)sourceCodeDocument;@end@interface IDEEditorContext : NSObject- (id)editor; // returns the current editor. If the editor is the code editor, the class is `IDESourceCodeEditor`@end@interface IDEEditorArea : NSObject- (IDEEditorContext *)lastActiveEditorContext;@end@interface IDEConsoleArea : NSObject- (IDEEditorContext *)lastActiveEditorContext;@end@interface IDEWorkspaceWindowController : NSObject@property (readonly) IDEWorkspaceTabController *activeWorkspaceTabController;- (IDEEditorArea *)editorArea;@end@interface DVTMapTable : NSObject <NSCopying, NSCoding, NSFastEnumeration>- (id)dictionaryRepresentation;@end@interface IDESourceControlProject : NSObject@property(retain) NSMutableDictionary *requiredConfigurationsDictionary; // @synthesize requiredConfigurationsDictionary=_requiredConfigurationsDictionary;@property(retain) NSMutableDictionary *repositoryRootForConfigurationDictionary; // @synthesize repositoryRootForConfigurationDictionary=_repositoryRootForConfigurationDictionary;@property(retain) NSMutableDictionary *relativeInstallPathForConfigurationDictionary; // @synthesize relativeInstallPathForConfigurationDictionary=_relativeInstallPathForConfigurationDictionary;@property(retain) NSMutableDictionary *originForConfigurationDictionary; // @synthesize originForConfigurationDictionary=_originForConfigurationDictionary;//@property(retain) DVTCustomDataSpecifier *customDataSpecifier; // @synthesize customDataSpecifier=_customDataSpecifier;@property(getter=isFavorite) BOOL favorite; // @synthesize favorite=_favorite;@property(retain) NSMutableArray *configurationsInCurrentWorkspace; // @synthesize configurationsInCurrentWorkspace=_configurationsInCurrentWorkspace;@property unsigned long long type; // @synthesize type=_type;//@property(retain) IDESourceControlWorkingCopyConfiguration *projectWCC; // @synthesize projectWCC=_projectWCC;@property(copy) NSString *relativePathToProject; // @synthesize relativePathToProject=_relativePathToProject;@property(copy) NSURL *projectURL; // @synthesize projectURL=_projectURL;@property(readonly) NSString *uniqueIdentifier; // @synthesize uniqueIdentifier=_uniqueIdentifier;@property(copy) NSString *name; // @synthesize name=_name;- (id)dictionaryRepresentation;@end@interface IDESourceControlWorkspaceMonitor : NSObject@property(retain) IDESourceControlProject *sourceControlProject; // @synthesize sourceControlProject=_sourceControlProject;@property(readonly) DVTMapTable *workspaceRootForWorkingTreeMapTable;@end@interface IDEWorkspace : NSWorkspace@property (readonly) DVTFilePath *representingFilePath;@property(readonly) NSString *representingTitle;- (id)displayName;@property(readonly) NSString *name;@property(retain) IDESourceControlWorkspaceMonitor *sourceControlWorkspaceMonitor; // @synthesize@end@interface IDEWorkspaceDocument : NSDocument@property (readonly) IDEWorkspace *workspace;@end@interface XCPCModel : NSObject@property (nonatomic, assign) id delegate;+ (NSString *)currentProjectName;+ (NSString *)applicationSupportFolder;+ (IDEWorkspaceDocument *)currentWorkspaceDocument;+ (IDEWorkspaceTabController*)tabController;+ (IDESourceCodeEditor*)currentEditor;+ (IDESourceControlWorkspaceMonitor *)sourceControlMonitor;+ (NSString *)currentProjectFile;+ (NSString *)currentRootPath;+ (void) cleanAllTempFiles;+ (NSString *) addPathSlash:(NSString *)path;+ (NSString *) rootPathMacro;+ (NSArray *) explandRootPathMacros:(NSArray *)paths projectPath:(NSString *)projectPath;+ (NSString *) explandRootPathMacro:(NSString *)path projectPath:(NSString *)projectPath;+ (NSString *) settingFilePathByProjectName:(NSString *)projectName;+ (XCPCProjectSetting *) projectSettingByProjectName:(NSString *)projectName;+ (void) saveProjectSetting:(XCPCProjectSetting *)projectSetting ByProjectName:(NSString *)projectName;@endextern NSString* const kNotifyProjectSettingChanged;