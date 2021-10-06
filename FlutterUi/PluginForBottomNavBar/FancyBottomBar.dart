//// i am using this plugin => fancy_bottom_navigation
//// Search it on google For more information.


import 'package:fancy_bottom_navigation/fancy_bottom_navigation.dart';
import 'package:flutter/material.dart';

class MyPlugin extends StatefulWidget {
  static const routeName = '/FancyBottomNavigationPage';

  @override
  _MyPluginState createState() => _MyPluginState();
}

class _MyPluginState extends State<MyPlugin> {
  int currentPage = 0;

  GlobalKey bottomNavigationKey = GlobalKey();

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(),
      body: Container(
        decoration: BoxDecoration(color: Colors.white),
        child: Center(
          child: _getPage(currentPage),
        ),
      ),
      bottomNavigationBar: FancyBottomNavigation(
        tabs: [
          TabData(
            iconData: Icons.home,
            title: "Home",
            onclick: () {},
          ),
          TabData(iconData: Icons.person, title: "Profile"),
          TabData(iconData: Icons.more_vert, title: "More")
        ],
        initialSelection: 1,
        key: bottomNavigationKey,
        onTabChangedListener: (position) {
          setState(
                () {
              currentPage = position;
            },
          );
        },
      ),
    );
  }

  _getPage(int page) {
    switch (page) {
      case 0:
        return Column(
          mainAxisSize: MainAxisSize.min,
          children: <Widget>[
            Text("This is the home page"),
          ],
        );
      case 1:
        return Column(
          mainAxisSize: MainAxisSize.min,
          children: <Widget>[
            Text("This is the Profile page"),
          ],
        );
      default:
        return Column(
          mainAxisSize: MainAxisSize.min,
          children: <Widget>[
            Text("This is the More page"),
          ],
        );
    }
  }
}