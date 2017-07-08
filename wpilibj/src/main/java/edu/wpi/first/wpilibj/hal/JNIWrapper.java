/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2016-2017. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

package edu.wpi.first.wpilibj.hal;

import java.io.File;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.ByteBuffer;
import edu.wpi.first.wpiutil.RuntimeDetector;

/**
 * Base class for all JNI wrappers.
 */
public class JNIWrapper {
  static boolean libraryLoaded = false;
  static File jniLibrary = null;
  static {
    if (!libraryLoaded) {
      try {
        System.loadLibrary("wpilibJNI");
      } catch (UnsatisfiedLinkError e) {
        try {
          String resname = RuntimeDetector.getLibraryResource("wpilibJNI");
          System.out.println(resname);
          InputStream is = JNIWrapper.class.getResourceAsStream(resname);
          if (is != null) {
            // create temporary file
            if (System.getProperty("os.name").startsWith("Windows"))
              jniLibrary = File.createTempFile("wpilibJNI", ".dll");
            else if (System.getProperty("os.name").startsWith("Mac"))
              jniLibrary = File.createTempFile("wpilibJNI", ".dylib");
            else
              jniLibrary = File.createTempFile("wpilibJNI", ".so");
            // flag for delete on exit
            jniLibrary.deleteOnExit();
            OutputStream os = new FileOutputStream(jniLibrary);

            byte[] buffer = new byte[1024];
            int readBytes;
            try {
              while ((readBytes = is.read(buffer)) != -1) {
                os.write(buffer, 0, readBytes);
              }
            } finally {
              os.close();
              is.close();
            }
            System.load(jniLibrary.getAbsolutePath());
          } else {
            System.loadLibrary("wpilibJNI");
          }
        } catch (IOException ex) {
          ex.printStackTrace();
          System.exit(1);
        }
      }
      libraryLoaded = true;
    }
  }
  /*
  static boolean libraryLoaded = false;
  static File jniLibrary = null;

  static {
    try {
      if (!libraryLoaded) {
        System.loadLibrary("wpilibJavaJNI");
        libraryLoaded = true;
      }

    } catch (Exception ex) {
      ex.printStackTrace();
      System.exit(1);
    }
  }
  */

  public static native int getPortWithModule(byte module, byte channel);

  public static native int getPort(byte channel);
}
