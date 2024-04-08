OptiTrack Unreal Engine Plugin
================================

The OptiTrack Unreal Engine Plugin allows you to stream real-time rigid body,
skeleton, and HMD tracking data into Unreal Engine 5.3.

For more information, refer to the documentation at the following URL:

    https://docs.optitrack.com/plugins/optitrack-unreal-engine-plugin



Installation
------------

The included plugins, contained within the "OptiTrack" directory, should be
extracted to your engine plugins directory. By default, this is:

    C:\Program Files\Epic Games\UE_5.3\Engine\Plugins\Marketplace\

You should end up with a directory hierarchy such as the following:

    C:\Program Files\Epic Games\UE_5.3\Engine\
    |-- Plugins
        |-- OptiTrack
            |-- OptitrackNatnet
                |-- OptitrackNatnet.uplugin
                |-- ...


Version History / Changelog
---------------------------
5.3 v2 (2024-01-03)
----
- Added individual subjects as components of OptitrackLiveLinkDisplay on actor creation
- Added trained markersets compatibility for Live Link
- Reorganized properties for OptitrackLiveLinkDisplay
- Fixed a problem where Unlabeled Markers were not displaying properly
- Added a standard Motive Skeletal Mesh to be used as a Base Skeleton for all other skeleton imports
- Added an IK Rig with the standard Skeletal Mesh to be used in retargeting practices
- Added a Active Puck Static Mesh to be used as a calibrator tool in ICVFX pipelines or to be used to measure scale in the level

5.3 v1 (2023-10-09)
----
- Unreal Engine 5.3 compatibility.
- Fixed a crash when enabling Unlabeled Markers.

5.2 v2 (2023-09-18)
----
- Added a root component to the Live Link Display actor.

5.2 v1 (2023-05-17)
----
- Unreal Engine 5.2 compatibility
- Updated the plugin icons

3.1.0 (2022-11-12)
----
- Unreal Engine 5.1 compatibility

3.0.3 (2022-10-04)
----
- Live Link Plugin: Added the option to include labeled or unlabeled markers by enabling them through the Live Link streaming client.
- Live Link Plugin: Fix for crash retargeting skeleton with different bone count in LODs.

3.0.2 (2021-04-12)
----
- Unreal Engine 5.0 compatibility

3.0.1 (2021-03-17)
----
- Unreal Engine 5.0 Preview 2 compatibility
- Updated the EULA. 
- Live Link Plugin: Added helper content for InCamera VFX Virtual Production.
- Live Link Plugin: Added an example bone model mesh for the Live Link plugin in the content folder.
- Streaming Client Plugin: Renamed the "Tracking ID" to "Streaming ID" to match Motive. 

3.0 (2021-01-05)
----
- Unreal Engine 5.0 Early Access 2 compatibility
- Switched the default bone naming convention to FBX for both plugins. 
- Live Link Plugin: Added an "OptiTrack Live Link Display" actor for visualizing the raw bone data from Motive.  
- Live Link Plugin: Fixed a bug with the thumb rotations for finger data.
- Streaming Client Plugin: Added a debug visualizer for camera positions.
- Streaming Client Plugin: Added the ability to change the debug marker color. 
- VR Latency Optimization: Temporarily removed this plugin due to a bug in Unreal Engine 5. 

2.27.2 (2021-03-17)
----
- Updated the EULA. 
- Live Link Plugin: Added helper content for InCamera VFX Virtual Production.
- Live Link Plugin: Added an example bone model mesh for the Live Link plugin in the content folder.  

2.27.1 (2021-01-05)
----
- Switched the default bone naming convention to FBX for both plugins. 
- Live Link Plugin: Added an "OptiTrack Live Link Display" actor for visualizing the raw bone data from Motive.  
- Live Link Plugin: Fixed a bug with the thumb rotations for finger data.
- Streaming Client Plugin: Added a debug visualizer for camera positions.
- Streaming Client Plugin: Added the ability to change the debug marker color. 

2.27 (2021-08-24)
----
- Unreal Engine 4.27 compatibility
- Updated to NatNet SDK 4.0 
- LiveLink Plugin: Added the ability to track skeletons using the Live Link plugin with bone remapping. 
- Streaming Client Plugin: Added longer wait times for rigid body subscription for overly congested networks. 
- Streaming Client Plugin: Put in checks for preventing a very infrequent crash with prerendering rigid bodies. 


2.26.1 (2021-10-13)
----
- Updated to NatNet SDK 4.0 
- LiveLink Plugin: Added the ability to track skeletons using the Live Link plugin with bone remapping. 
- Streaming Client Plugin: Added longer wait times for rigid body subscription for overly congested networks. 
- Streaming Client Plugin: Put in checks for preventing a very infrequent crash with prerendering rigid bodies. 
- Streaming Client Plugin: Added the ability to change the marker colors. 


2.26 (2020-12-09)
----
- Unreal Engine 4.26 compatibility


2.25.2 (2020-12-03)
----
- Added an additional plugin for Live Link. The initial plugin is limited to animating cameras and object files in Unreal Engine with optional timecode support. 


1.25 (2020-07-27)
----
- Unreal Engine 4.25 compatibility


1.24 (2020-04-07)
----
- Unreal Engine 4.24 compatibility
- Network compensation. Provides a smoother experience by adding the ability to compensate for noisy wireless environments.
- Optitrack VR Latency Optimization. Added an additional plugin that helps reduce the perception of latency when using the OptiTrack OpenVR driver. (SteamVR plugin must be enabled.)
- Unicast subscription. Added the ability to subscribe to data with Unicast connection to Motive. This ensures that only necessary information is streamed to the client minimizing wireless traffic. (Compatible with Motive 2.2+)


1.23 (2020-01-14)
----
- Unreal Engine 4.23 compatibility
- Oculus support deprecated
- Better bone scaling in Bone Mapping tool.
- Better handling of all non-full Motive skeletons, e.g. hand only skeletons
- Added support for sockets in Bone Mapping tool. Allows for quick modifications to bone locations of character.


1.22 (2019-10-30)
----
- Unreal Engine 4.22 compatability
- Hmd Rigid body Id property of client origin renamed to Oculus Hmd Rigid Body Id (as it is only necessary for Oculus Headsets).
- Deprecated support for Android/x86 platforms.


1.21 (2019-04-16)
----
- Unreal Engine 4.21 compatability
- Labeled marker positions are exposed via blueprint in client origin.
- Added 'Draw Markers' switch to Client origin. When enabled (defaults to false) labeled markers from Motive will be drawn in the scene.
- Added 'Hide on Invalid Definition' switch to rigid body actors. Actors are invisible if no associated rigid body definition from Motive.  Defaults to true (and updates dynamically).


1.20 (2018-12-21)
----
- Unreal Engine 4.20 compatability
- Updated NatNetLib to 3.1.0
- Auto-connect feature. By default the Optitrack NatNet plugin will search for and connect to Motive automatically (connection settings do not need to be set beforehand). When this feature is on, if the plugin hasn't recieved a frame in a few seconds, it'll attempt to search for and connect to Motive again. Users can open/close Motive or start/stop streaming without restarting their Unreal experience. This feature is NOT supported on Android.
- Optitrack Skeleton Component 'Hide on Invalid Definition' switch. Optitrack UE skeletons are hidden by default if they do not receive a valid skeleton definition from Motive. Updates dynamically.
- Experimental bone mapping roll bone support. Streaming skeletons now supports arm rollbones for some characters. This feature is experimental.
- Added 'Respect Parent Transform' option to rigid body component to treat parent as the origin. Useful for teleporting pawns and wanting to maintain a relative position/orientation to a rigid body.
- Fix for jitter bug when mirrors are in the scene.


1.9.2 (2018-07-30)
----
- Unreal Engine 4.19 compatibility.
- Streaming skeletons into Unreal is now supported. Allows users to use a bone mapping to use Motive skeleton data to drive character animations. See wiki for details: http://wiki.optitrack.com/index.php?title=OptiTrack_Unreal_Engine_4_Plugin
- Plugin is now open source to allow users to build themselves.


1.8.3 (2018-04-27)
-----
- Unreal Engine 4.18.3 compatibility.
- IMPORTANT: Rigid body components now only affect child components (like motion controller components). 
- Added Optitrack Rigid Body Actor class for simplicity given new rigid body component behaviour.
- Added render thread late update for rigid bodies for lower latency rendering.
- Added ability to control when OptiTrack Client Origin is initialized for dynamic setting of connection info. Blueprint accessible.


1.7.0 (2017-10-31)
-----
- Unreal Engine 4.17 compatibility.
- Updated NatNetLib to build 37477.
- FOptitrackRigidBodyState timestamps are now based on camera exposure timing
  information (where available).
- Added real-time graphing of NatNet 3.0+ latency metrics, accessible via
  console command `OptiTrack.ToggleDebugHud`.


1.6.0 (2017-08-22)
----
- Unreal Engine 4.16 compatibility.


1.5.1 (2017-08-15)
-----
- Updated NatNetLib to build 36302.
- Added some intermediary build artifacts required to compile references to,
  and link against, OptitrackNatnet classes from within user/game code.


1.5.0 (2017-05-10)
-----
- Unreal Engine 4.15 compatibility.


1.4.0 (2017-05-10)
-----
- Unreal Engine 4.14 compatibility.
- Added blueprint accessibility annotations to several properties and methods.
- Added module API linkage macro to OptitrackNatnet classes.
- Fixed some situations in which unnecessary DNS or reverse DNS lookups could
  cause a hang during initial NatNet streaming connection attempts.


1.3.0 (2016-10-14)
-----
- Unreal Engine 4.13 compatibility.
- Improved handling of stale pose data for untracked rigid bodies.
- Improved detection and handling of client connection errors.
- Fixed a potential race condition during shutdown.


1.2.0 (2016-08-23)
-----
- Unreal Engine 4.12 compatibility.
- Gear VR support.


1.1.0 (2016-05-26)
-----
- Rift plugin updated for UE 4.11.1+ and Oculus SDK 1.3+. Supports Rift CV1.
- Added a check and error message when attaching a rigid body component to a
  client origin actor, which would otherwise cause bad behavior.
- Fixed rigid body pose timestamps getting truncated (double -> float).
- Use FCriticalSection instead of CRITICAL_SECTION.


1.0.0 (2016-03-14)
-----
- Initial release.
