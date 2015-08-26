#NewNDKTest
NDK project template using Android Studio v1.3 & Gradle 2.5 & Experimental android plugin.
##Introduction
Due to android plugin has been updated, the gradle script need to be modified to add NDK support.

** This project is inspried by this post [NDK Developing Using Android Studio v1.3 (Chinese)](http://blog.csdn.net/g707175425/article/details/47154115) **


I have to say this new gradle script is better than the old one, but it's a pain in the arse to porting old projects to new one.

I hope this sample will give you a quick jump start on your NDK projects.

##Project Structure
This project is a test project.

Only thing it does is display a string returned from native code.

#####But, it contains new gradle script and project configs. 
#####Consider this is a backup & reference for my own.

##Gradle Part
Follow below instructions to modify your scripts.

1. Change your gradle to v2.5 if you are using an older version. (You may need to modify your `gradle-wrapper.properties` file)

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
			
	* Using equation (`a = b`) when passing value to variables
			
	* In the new script grammar, `android` module is located in `model` section. So wrap your `android` module with a `model` module.
	
			apply plugin: 'com.android.model.application'
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
	* As for the `buildType`, `sources`, `productFlavors` and other gradle modules, they are moved to outside of 'android' module but with an 'android' prefix.

			apply plugin: 'com.android.model.application'
			model {
    			android {
        			....
        		}
    		}
			android.buildTypes {
	            release {
	                isMinifyEnabled = false
	                proguardFiles += file('proguard-rules.pro')
	            }
	        }
	        android.sources {
	            main{
	                java {
	                    source{
	                        srcDir 'src'
	                    }
	                }
	            }
	        }
	        android.ndk {
	            moduleName="JNITest"
	            ldLibs += 'log'
	            ldLibs += 'z'
	            ldLibs += 'm'
	            abiFilters += "armeabi"
	            abiFilters += "armeabi-v7a"
	            abiFilters += "x86"
	        }
	        
##Java Part
* Add an jni folder to your project by - 

		Right click your src/main folder and choose 'New' => 'Folder(with an droid icon)' => 'JNI Folder'.
		
* Create a java class in your package (NOT THE JNI FOLDER WE JUST CREATED!) and declare some native method in it.
* Use `javah` to generate header.
* Implement native method.
* Build, Run, Have fun.
	        