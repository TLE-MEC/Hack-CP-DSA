//// i am using this plugin => flip_box_bar
//// Search it on google For more information.


import 'package:flip_box_bar/flip_box_bar.dart';
import 'package:flutter/material.dart';

class MyPlugin extends StatefulWidget {
  static const routeName = '/FlipBottomNavigationBarPage';

  @override
  _MyPluginState createState() => _MyPluginState();
}

class _MyPluginState extends State<MyPlugin> {
  int selectedIndex = 0;

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(),
      body: Column(), //
      bottomNavigationBar: FlipBoxBar(
        selectedIndex: selectedIndex,
        items: [
          FlipBarItem(
              icon: Icon(Icons.home),
              text: Text("Home"),
              frontColor: Colors.blue,
              backColor: Colors.blueAccent),
          FlipBarItem(
              icon: Icon(Icons.favorite),
              text: Text("Favorite"),
              frontColor: Colors.cyan,
              backColor: Colors.cyanAccent),
          FlipBarItem(
              icon: Icon(Icons.person),
              text: Text("Profile"),
              frontColor: Colors.orange,
              backColor: Colors.orangeAccent),
          FlipBarItem(
              icon: Icon(Icons.notifications_active),
              text: Text("Notifications"),
              frontColor: Colors.purple,
              backColor: Colors.purpleAccent),
          FlipBarItem(
              icon: Icon(Icons.settings),
              text: Text("Settings"),
              frontColor: Colors.pink,
              backColor: Colors.pinkAccent),
        ],
        onIndexChanged: (newIndex) {
          setState(
                () {
              selectedIndex = newIndex;
            },
          );
        },
      ),
    );
  }
}