-- phpMyAdmin SQL Dump
-- version 2.6.1
-- http://www.phpmyadmin.net
-- 
-- Host: localhost
-- Generation Time: Aug 10, 2009 at 04:26 PM
-- Server version: 5.0.18
-- PHP Version: 5.1.6
-- 
-- Database: `mcdm`
-- 

-- --------------------------------------------------------

-- 
-- Table structure for table `characteristic`
-- 

DROP TABLE IF EXISTS `characteristic`;
CREATE TABLE IF NOT EXISTS `characteristic` (
  `ID` int(11) NOT NULL auto_increment,
  `title` varchar(127) NOT NULL,
  `measure` varchar(127) NOT NULL,
  PRIMARY KEY  (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 AUTO_INCREMENT=5 ;

-- 
-- Dumping data for table `characteristic`
-- 

INSERT INTO `characteristic` (`ID`, `title`, `measure`) VALUES (1, 'weight', 'kg');
INSERT INTO `characteristic` (`ID`, `title`, `measure`) VALUES (2, 'energy', 'kW/h');
INSERT INTO `characteristic` (`ID`, `title`, `measure`) VALUES (3, 'cost', 'USD');
INSERT INTO `characteristic` (`ID`, `title`, `measure`) VALUES (4, 'some new resource', 'measure');

-- --------------------------------------------------------

-- 
-- Table structure for table `compStates`
-- 

DROP TABLE IF EXISTS `compStates`;
CREATE TABLE IF NOT EXISTS `compStates` (
  `ID` int(11) NOT NULL auto_increment,
  `IDcomponent` int(11) NOT NULL,
  `IDstate` int(11) NOT NULL,
  PRIMARY KEY  (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 AUTO_INCREMENT=11 ;

-- 
-- Dumping data for table `compStates`
-- 

INSERT INTO `compStates` (`ID`, `IDcomponent`, `IDstate`) VALUES (1, 1, 1);
INSERT INTO `compStates` (`ID`, `IDcomponent`, `IDstate`) VALUES (2, 1, 2);
INSERT INTO `compStates` (`ID`, `IDcomponent`, `IDstate`) VALUES (3, 2, 3);
INSERT INTO `compStates` (`ID`, `IDcomponent`, `IDstate`) VALUES (4, 2, 4);
INSERT INTO `compStates` (`ID`, `IDcomponent`, `IDstate`) VALUES (5, 2, 5);
INSERT INTO `compStates` (`ID`, `IDcomponent`, `IDstate`) VALUES (6, 2, 6);
INSERT INTO `compStates` (`ID`, `IDcomponent`, `IDstate`) VALUES (7, 3, 7);
INSERT INTO `compStates` (`ID`, `IDcomponent`, `IDstate`) VALUES (8, 3, 8);
INSERT INTO `compStates` (`ID`, `IDcomponent`, `IDstate`) VALUES (9, 3, 9);

-- --------------------------------------------------------

-- 
-- Table structure for table `component`
-- 

DROP TABLE IF EXISTS `component`;
CREATE TABLE IF NOT EXISTS `component` (
  `ID` int(11) NOT NULL auto_increment,
  `title` varchar(127) NOT NULL,
  `type` enum('binary','monotone','general','3SC') default 'binary',
  `isEval` enum('yes','no') default 'no',
  PRIMARY KEY  (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 AUTO_INCREMENT=4 ;

-- 
-- Dumping data for table `component`
-- 

INSERT INTO `component` (`ID`, `title`, `type`, `isEval`) VALUES (1, '1st test unit', 'binary', 'no');
INSERT INTO `component` (`ID`, `title`, `type`, `isEval`) VALUES (2, '2nd test unit', 'monotone', 'no');
INSERT INTO `component` (`ID`, `title`, `type`, `isEval`) VALUES (3, '3rd test unit', '3SC', 'no');

-- --------------------------------------------------------

-- 
-- Table structure for table `resourceUsage`
-- 

DROP TABLE IF EXISTS `resourceUsage`;
CREATE TABLE IF NOT EXISTS `resourceUsage` (
  `IDcomponent` int(11) NOT NULL,
  `IDcharacteristic` int(11) NOT NULL,
  `value` float NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=cp1251;

-- 
-- Dumping data for table `resourceUsage`
-- 

INSERT INTO `resourceUsage` (`IDcomponent`, `IDcharacteristic`, `value`) VALUES (1, 1, 5);
INSERT INTO `resourceUsage` (`IDcomponent`, `IDcharacteristic`, `value`) VALUES (2, 1, 4);
INSERT INTO `resourceUsage` (`IDcomponent`, `IDcharacteristic`, `value`) VALUES (1, 2, 100);
INSERT INTO `resourceUsage` (`IDcomponent`, `IDcharacteristic`, `value`) VALUES (2, 2, 120);
INSERT INTO `resourceUsage` (`IDcomponent`, `IDcharacteristic`, `value`) VALUES (1, 3, 150);
INSERT INTO `resourceUsage` (`IDcomponent`, `IDcharacteristic`, `value`) VALUES (2, 3, 175);
INSERT INTO `resourceUsage` (`IDcomponent`, `IDcharacteristic`, `value`) VALUES (3, 1, 7);
INSERT INTO `resourceUsage` (`IDcomponent`, `IDcharacteristic`, `value`) VALUES (3, 3, 320);
INSERT INTO `resourceUsage` (`IDcomponent`, `IDcharacteristic`, `value`) VALUES (3, 2, 230);

-- --------------------------------------------------------

-- 
-- Table structure for table `state`
-- 

DROP TABLE IF EXISTS `state`;
CREATE TABLE IF NOT EXISTS `state` (
  `ID` int(11) NOT NULL auto_increment,
  `title` varchar(127) NOT NULL,
  `description` varchar(255) NOT NULL,
  `idx` tinyint(4) default NULL,
  `type` enum('perfect','quality_level','failure_mode') NOT NULL,
  PRIMARY KEY  (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 AUTO_INCREMENT=11 ;

-- 
-- Dumping data for table `state`
-- 

INSERT INTO `state` (`ID`, `title`, `description`, `idx`, `type`) VALUES (1, 'perfect functioning', '', 1, 'perfect');
INSERT INTO `state` (`ID`, `title`, `description`, `idx`, `type`) VALUES (2, 'failure', '', 0, 'perfect');
INSERT INTO `state` (`ID`, `title`, `description`, `idx`, `type`) VALUES (3, 'perfect functioning', '', 4, 'perfect');
INSERT INTO `state` (`ID`, `title`, `description`, `idx`, `type`) VALUES (4, 'good functioning', '', 3, 'perfect');
INSERT INTO `state` (`ID`, `title`, `description`, `idx`, `type`) VALUES (5, 'weak functioning', '', 2, 'perfect');
INSERT INTO `state` (`ID`, `title`, `description`, `idx`, `type`) VALUES (6, 'broken', '', 1, 'perfect');
INSERT INTO `state` (`ID`, `title`, `description`, `idx`, `type`) VALUES (7, 'failure open mode', 'component fails in open mode', 0, 'perfect');
INSERT INTO `state` (`ID`, `title`, `description`, `idx`, `type`) VALUES (8, 'failure short mode', 'component fails in short mode ', 1, 'perfect');
INSERT INTO `state` (`ID`, `title`, `description`, `idx`, `type`) VALUES (9, 'functioning', '3s component functions', 2, 'perfect');
INSERT INTO `state` (`ID`, `title`, `description`, `idx`, `type`) VALUES (10, 'some new state', 'some new state description', 3, 'quality_level');
        