#NewNDKTest
NDK project template using Android Studio v1.3 & Gradle 2.5 & Experimental android plugin.
##Introduction
Due to android plugin has been updated, the gradle script need to be modified to add NDK support.

** This project is inspried by this post [NDK Developing Using Android Studio v1.3 (Chinese)](http://blog.csdn.net/g707175425/article/details/47154115) **


I have to say this new gradle script is better than the old one, but it's a pain in the arse to porting old projects to new one.

##Project Structure
This project is a test project.

Only thing it does is display a string returned from native code.

** But, it contains new gradle script and project configs. **

Consider this is a backup & reference for my own.

##Gradle Part
Follow below instructions to modify your scripts.

1. Change your gradle to v2.5 if you are using an older version.

2. Using experimental android plugin by changing `build.gradle` in your project ** root ** folder.
	
		buildscript {
    		repositories {
    	    	jcenter()
    		}
    		dependencies {
				classpath 'com.android.tools.build:gradle-experimental:0.1.0'
    		}
		}

		allprojects {
    		repositories {
        		jcenter()
    		}
		}
		
3. Change `build.gradle` in your app module.
	* Using 'com.android.model.application' plugin instead of the old one by changing the first line of this file.
	
			apply plugin: 'com.android.model.application'
			
	* In the new script grammar, `android` module is located in `model` section. So wrap your `android` module with a `model` module.
	
			model {
    			android {
        			compileSdkVersion = 22
        			buildToolsVersion = "22.0.1"

        		defaultConfig.with {
            		applicationId = "sun.bob.newndktest"
            		minSdkVersion.apiLevel = 8
            		targetSdkVersion.apiLevel = 23
            		versionCode = 1
            		versionName = "1.0"
        		}
        		tasks.withType(JavaCompile) {
            		sourceCompatibility = JavaVersion.VERSION_1_7
            		targetCompatibility = JavaVersion.VERSION_1_7
        		}
    		}
	* 
		
		
#TO BE CONTINUED!