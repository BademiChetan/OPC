-- phpMyAdmin SQL Dump
-- version 3.4.4deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Sep 23, 2011 at 03:48 PM
-- Server version: 5.1.58
-- PHP Version: 5.3.3-7

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `automania`
--

-- --------------------------------------------------------

--
-- Table structure for table `auth_user`
--

CREATE TABLE IF NOT EXISTS `auth_user` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(30) NOT NULL,
  `first_name` varchar(30) NOT NULL,
  `last_name` varchar(30) NOT NULL,
  `email` varchar(75) NOT NULL,
  `password` varchar(128) NOT NULL,
  `is_staff` tinyint(1) NOT NULL,
  `is_active` tinyint(1) NOT NULL,
  `is_superuser` tinyint(1) NOT NULL,
  `last_login` datetime NOT NULL,
  `date_joined` datetime NOT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=80 ;

--
-- Dumping data for table `auth_user`
--

INSERT INTO `auth_user` (`id`, `username`, `first_name`, `last_name`, `email`, `password`, `is_staff`, `is_active`, `is_superuser`, `last_login`, `date_joined`) VALUES
(1, 'sujeet', '', '', 'sujeetgholap@gmail.com', 'sha1$c3143$1f9de18d47a1757d096ac02af4e9e5eeaa13e733', 1, 1, 1, '2011-09-21 12:39:08', '2011-09-06 19:27:48'),
(6, 'kthxbye', '', '', 'cpliitm@gmail.com', 'sha1$98e5f$d0dd4540f64e4a4405b42c1a13e89de1c7dad934', 0, 1, 0, '2011-09-08 16:12:49', '2011-09-08 16:08:42'),
(3, 'sujeetgholap', '', '', 'sujeetgholap@gmail.com', 'sha1$88e82$1b36df19e7d515ee15ff5354494ae7d0207d998e', 0, 1, 0, '2011-09-13 19:40:05', '2011-09-07 19:56:51'),
(4, 'AutoBots', '', '', 'm.magesh.66@gmail.com', 'sha1$62db3$b99e40dbaa37799181574a0cbced0a416bed26e6', 0, 1, 0, '2011-09-08 09:13:09', '2011-09-08 09:12:58'),
(5, 'Xingads', '', '', 'dev344@gmail.com', 'sha1$e8812$2d5c242d58a54cfeb32865f24ead24c09cbcde5e', 1, 1, 1, '2011-09-08 13:01:37', '2011-09-08 13:01:13'),
(7, 'TronGods', '', '', 'guruprakash991@gmail.com', 'sha1$a3b55$1d45626bd02ff9e0bc354528bfd35e175fc94118', 0, 1, 0, '2011-09-13 11:14:04', '2011-09-08 17:05:42'),
(8, 'B@mBino', '', '', 'anu_still_rocks@in.com', 'sha1$39490$1bc1eb0af87688faee92e464c9068de28ab50ce3', 0, 1, 0, '2011-09-13 21:32:18', '2011-09-08 18:05:49'),
(9, 'mouzer', '', '', 'bittusrk@gmail.com', 'sha1$22b7c$92798108dd1cbed40f2798934d4011a91e649c75', 0, 1, 0, '2011-09-23 14:14:30', '2011-09-08 18:38:00'),
(10, 'GMATRIX', '', '', 'tnmraja@gmail.com', 'sha1$e0d7c$5bd0488e3af5f21ec9cba719f26eac7569704f9e', 0, 1, 0, '2011-09-11 02:39:00', '2011-09-08 19:23:06'),
(11, 'automania_returns', '', '', 'nkartr@gmail.com', 'sha1$9ab57$056ae710fdf5d3dfd6780d678b03d3edf6956da2', 0, 1, 0, '2011-09-22 05:44:12', '2011-09-08 20:35:31'),
(12, 'Techsmiths', '', '', 'rahul.ponnada@gmail.com', 'sha1$e5a44$8d7d6eb77bb4e363b242dee1b7588ad716e95cca', 0, 1, 0, '2011-09-08 21:26:19', '2011-09-08 21:26:05'),
(13, 'CODEDnBYTEN', '', '', 'tanoy2106@gmail.com', 'sha1$0dd78$c87634e265644f5f0b047da7bc0e90efa6d91edd', 0, 1, 0, '2011-09-22 06:42:26', '2011-09-08 21:51:47'),
(14, 'cavemanzzz', '', '', 'chetanbademi@gmail.com', 'sha1$e993c$b5fe0dd0594c3db3a0d45bdb332a5adb1d77c2c4', 0, 1, 0, '2011-09-10 21:02:37', '2011-09-09 18:27:27'),
(15, 'angry_coder', '', '', 'cegprakash@gmail.com', 'sha1$a3993$3db2db1947dcf7fa9b303b27237ef01f5d360ad9', 0, 1, 0, '2011-09-19 18:04:08', '2011-09-09 20:21:32'),
(16, 'behemoth', '', '', 'stc.043@gmail.com', 'sha1$584ee$06189aa080231a7f6b0c3c2d38063d2395a4082d', 0, 1, 0, '2011-09-09 21:00:35', '2011-09-09 21:00:23'),
(17, 'robogods', '', '', 'gowtham_champ@yahoo.com', 'sha1$677fe$3734deed08fe14a8ee8f58d18f114efd9ce1b281', 0, 1, 0, '2011-09-09 21:47:46', '2011-09-09 21:47:25'),
(18, 'legends', '', '', 'ravindran.maha@gmail.com', 'sha1$620a9$1619c10b0154ff126aba72a5aab889d945070acd', 0, 1, 0, '2011-09-10 00:19:35', '2011-09-10 00:19:00'),
(19, 'tron', '', '', 'gopavarapu1993@gmail.com', 'sha1$10925$8d9b6dcf7b7c1ee5b37012c9c410ccf0b4a1974b', 0, 1, 0, '2011-09-21 15:51:32', '2011-09-10 11:18:24'),
(20, 'MEC', '', '', 'technokids4u@gmail.com', 'sha1$551c6$134f69051709933f04bfbdfecfb20eca0764ba90', 0, 1, 0, '2011-09-16 18:22:51', '2011-09-10 20:22:52'),
(21, 'trioppl', '', '', 'cheenu.daredevil@gmail.com', 'sha1$25b7c$9417d963bef6bdf8d1e322d0b9cadb036287f879', 0, 1, 0, '2011-09-17 06:14:47', '2011-09-11 06:35:25'),
(22, 'RoundTable', '', '', 'adithya.bhatp@gmail.com', 'sha1$0a11b$b8a27df758a302a9b2edaa1f33733e72ce5d8c35', 0, 1, 0, '2011-09-17 07:38:57', '2011-09-11 08:13:20'),
(23, 'untitled_botmakers', '', '', 'abdul.raaziq@yahoo.com', 'sha1$31763$79179e3af2f82dd9a265c36103c3206679002b4e', 0, 1, 0, '2011-09-11 09:34:47', '2011-09-11 09:34:19'),
(24, 'invinsible', '', '', 'smartprudhvi@gmail.com', 'sha1$30223$ca5d8994289781f955551bbe34cc8dd3e3d01551', 0, 1, 0, '2011-09-11 10:15:11', '2011-09-11 10:14:47'),
(25, 'Blitzkriez_Boyz', '', '', 'psaibhushan@ymail.com', 'sha1$39dc5$0bbbfc39b75086218a961e83b5475a86d59643fe', 0, 1, 0, '2011-09-21 19:47:19', '2011-09-11 12:29:07'),
(26, 'eminentengineers', '', '', 'ganesh.kit.eeeguy@gmail.com', 'sha1$6050b$862b0ff7578904fd4cf0d1a4fbfcbc86f2f2623e', 0, 1, 0, '2011-09-11 13:25:59', '2011-09-11 13:23:45'),
(27, 'eminents', '', '', 'ganesh.kit.eeeguy@gmail.com', 'sha1$0a1f0$0821c2ad9e9ef542d919c583b3249b8413554285', 0, 1, 0, '2011-09-11 13:24:41', '2011-09-11 13:24:41'),
(28, 'energex', '', '', 'sriramdines@gmail.com', 'sha1$1ab4f$c6c0a03b266239f9235120a9163401f54d3fec74', 0, 1, 0, '2011-09-11 15:39:45', '2011-09-11 15:39:32'),
(29, 'zugzwang', '', '', 'rudradevb@gmail.com', 'sha1$6af9e$1b7d54936e4f3512a6dc7bf24044581f6622f119', 0, 1, 0, '2011-09-22 05:53:51', '2011-09-11 19:42:49'),
(30, '_teaM-0x90', '', '', 'sailsk8r@gmail.com', 'sha1$90871$5135afbcfab1f1eb93e31349e4260a9607a904e7', 0, 1, 0, '2011-09-12 18:10:09', '2011-09-11 21:45:45'),
(31, 'sml', '', '', 'shruthe92@yahoo.com', 'sha1$de9c9$13007eb46e231a262ce8d5f260cfb3f6a493563a', 0, 1, 0, '2011-09-12 08:23:57', '2011-09-12 08:23:35'),
(32, 'nssprogrammer', '', '', 'lucky.nssprogrammer@gmail.com', 'sha1$b7bc1$211be461078fccde36533a5bc70ddd139759a5b5', 0, 1, 0, '2011-09-22 14:40:00', '2011-09-12 15:46:56'),
(33, 'mechackers', '', '', 'nikhiltitusk@gmail.com', 'sha1$0c697$331631bc0153c25d3ac59a49bf1f937ab75f9f71', 0, 1, 0, '2011-09-12 17:55:33', '2011-09-12 17:55:15'),
(34, 'manav', '', '', 'manav_nanu@yahoo.co.in', 'sha1$7657a$ed80929dcd13908b552669cb1bc8ed79a538a90c', 0, 1, 0, '2011-09-12 19:27:32', '2011-09-12 19:27:21'),
(35, 'automaniacs', '', '', 'sid24ss@gmail.com', 'sha1$cc8dd$be611056b03a190a39e81e06fef08ed6156f2f77', 0, 1, 0, '2011-09-12 21:29:24', '2011-09-12 21:24:48'),
(36, 'falcons', '', '', 'mdsalmanabid@gmail.com', 'sha1$2210f$361451fdbb7b5a353889128c942328652d2541f0', 0, 1, 0, '2011-09-12 21:29:27', '2011-09-12 21:28:52'),
(37, 'Bluffcoders', '', '', 'namanjainb2@gmail.com', 'sha1$53d28$837a097422578cd7582f0464be60c3c8cd82f260', 0, 1, 0, '2011-09-13 14:33:57', '2011-09-13 14:33:48'),
(38, 'anziegers', '', '', 'anzigersprem@gmail.com', 'sha1$8f756$d3a5a760a8cf91212815b6867072eb2b82df95a6', 0, 1, 0, '2011-09-13 17:15:59', '2011-09-13 17:15:39'),
(39, 'cavemenandfarmerzzz', '', '', 'chetanbademi@gmail.com', 'sha1$043ca$492e33ddebe3d949f18b55c78a421a8c614c1069', 0, 1, 0, '2011-09-20 16:58:21', '2011-09-13 21:43:09'),
(40, 'chn', '', '', 'cdbapat92@gmail.com', 'sha1$710c2$493b64070acb2016b8e682c0c7caa81c675766e7', 0, 1, 0, '2011-09-14 07:59:50', '2011-09-14 04:59:31'),
(41, 'RichaSingh', '', '', 'richa.sngh908@gmail.com', 'sha1$382eb$cce85d1313345f920fdf43b56b3330cf85fecdd6', 0, 1, 0, '2011-09-14 08:10:04', '2011-09-14 08:09:38'),
(42, 'Aaron@Kevin', '', '', 'abiphor@indiatimes.com', 'sha1$9c601$01b403dd8c315074cff287bf4fdf335a9fe05610', 0, 1, 0, '2011-09-14 10:28:09', '2011-09-14 10:27:50'),
(43, 'SAMYAK', '', '', 'mahesh.raksha@yahoo.com', 'sha1$83e32$7a442d242b222e479422cfa4f84fa4204b44e2b7', 0, 1, 0, '2011-09-14 14:35:40', '2011-09-14 14:35:25'),
(44, 'xD', '', '', 'tirumarai.selvan@gmail.com', 'sha1$0c272$6e7de9465bbfe847c50914f4cf5c166202b42cb9', 0, 1, 0, '2011-09-14 16:15:19', '2011-09-14 16:15:19'),
(45, 'ABCD', '', '', 'check@gmail.com', 'sha1$ed930$6d1f545c14335bd00f430313d0158b3d57b61eb7', 0, 1, 0, '2011-09-14 17:42:55', '2011-09-14 17:42:55'),
(46, 'STANDALONE', '', '', 'pavansoni59@yahoo.com', 'sha1$b236a$033f5f8cf6c740a289fff2250927fe513f602669', 0, 1, 0, '2011-09-15 15:14:25', '2011-09-15 15:13:36'),
(47, 'redhat', '', '', 'varundixit91@gmail.com', 'sha1$1f8de$39356f2b9a20cdfe84f193f78ad61276907e8a03', 0, 1, 0, '2011-09-15 17:33:12', '2011-09-15 17:32:17'),
(48, 'Hassassins', '', '', 'vakaash@yahoo.co.in', 'sha1$0dd7b$7a9fe592b8e963ec673d5d97fa0d30879bc4f634', 0, 1, 0, '2011-09-15 17:55:22', '2011-09-15 17:54:57'),
(49, 'untitled', '', '', 'sathya.tvr.cbe@gmail.com', 'sha1$e15db$870796941d937a27a02b3cf113e79db4917f57d5', 0, 1, 0, '2011-09-17 19:23:25', '2011-09-16 09:10:08'),
(50, 'bazinga', '', '', 'vageesh.dc@gmail.com', 'sha1$5868d$b45ca77d9bf9f2e24707c1a0d17d73611b9bbb35', 0, 1, 0, '2011-09-16 15:20:35', '2011-09-16 15:20:22'),
(51, 'trojans', '', '', 'm.harishkumar.m@gmail.com', 'sha1$bd16b$23d59d0978deb3c67dfb9aea2d6a4b6f67c42ad7', 0, 1, 0, '2011-09-16 17:19:46', '2011-09-16 17:19:46'),
(52, 'megatron', '', '', 'kannankarthik1992@gmail.com', 'sha1$9c5b4$e083ba2755a997249f695cc4a55ead11a1c20fb0', 0, 1, 0, '2011-09-16 18:02:46', '2011-09-16 18:02:19'),
(53, 'siyan', '', '', 'sabarinathan1991@gmail.com', 'sha1$66b94$ea01ddf93311abfe27e182cd8189f15778774491', 0, 1, 0, '2011-09-16 21:42:24', '2011-09-16 21:41:21'),
(54, 'Autobot', '', '', 'm.magesh.66@gmail.com', 'sha1$f5dfa$68d3d7f510b7746936ceaa6c2411e7e25f73bade', 0, 1, 0, '2011-09-17 10:12:08', '2011-09-17 10:12:00'),
(55, 'Cresbatross', '', '', 'bakshi_gulam@yahoo.com', 'sha1$8df1f$1418607219d2c8e5afd9d61dd195daee4ad1c62d', 0, 1, 0, '2011-09-17 16:34:23', '2011-09-17 16:34:12'),
(56, 'cusatit', '', '', 'vimal_hayabusa@yahoo.com', 'sha1$44938$cfccc8d498b7cc579e69065f7b0c87ad76f0ee49', 0, 1, 0, '2011-09-17 17:19:11', '2011-09-17 17:18:56'),
(57, 'ssecspark', '', '', 'natarajan.ramanathan93@gmail.com', 'sha1$1a437$f0e956de4ebd3e38c7e7e2f7227097d1b1e38925', 0, 1, 0, '2011-09-17 17:26:59', '2011-09-17 17:26:41'),
(58, 'amuzer', '', '', 'kavin.friendship@gmail.com', 'sha1$8c93c$6079a0991432e1cc8076f5b0e332e68d45a1edcd', 0, 1, 0, '2011-09-18 11:48:23', '2011-09-18 11:48:03'),
(59, 'lightening', '', '', 'kumarssk8@gmail.com', 'sha1$edfe1$0771ef17699af65f5db124c941e8635a2111c312', 0, 1, 0, '2011-09-18 19:22:44', '2011-09-18 19:22:21'),
(60, 'zyberkiddy', '', '', 'zyberkiddy@yahoo.com', 'sha1$56fda$d532415fdd66ed97569f79619ed60ef4cf6266b2', 0, 1, 0, '2011-09-20 19:49:56', '2011-09-18 20:40:23'),
(61, 'YagamiLight', '', '', 'ankmahato@gmail.com', 'sha1$0a39a$4fe2dd0fb7db6edd1c564e68a41f9a652a0ba22b', 0, 1, 0, '2011-09-20 10:04:10', '2011-09-19 00:23:59'),
(62, 'kastron', '', '', 'architb@iitk.ac.in', 'sha1$f491e$ae8eb68531cbb5568e37a910cae2476fd1655b08', 0, 1, 0, '2011-09-19 01:20:45', '2011-09-19 01:20:35'),
(63, 'United10', '', '', 'nivruth.n@gmail.com', 'sha1$9e397$1af5cd299d5bea7f1522c52e2720b25b744ec5a0', 0, 1, 0, '2011-09-19 14:03:12', '2011-09-19 14:02:56'),
(64, 'arbit', '', '', 'rishabhnigam31@gmail.com', 'sha1$12ff6$f90987bc30a036e80febdb980d708ac149389cd4', 0, 1, 0, '2011-09-19 16:33:00', '2011-09-19 16:33:00'),
(65, 'Algorist', '', '', 'hiteshfrnds@gmail.com', 'sha1$b3784$931ff785a812fda4e11f23ba06fec78b7f03efe3', 0, 1, 0, '2011-09-22 04:06:14', '2011-09-20 00:39:55'),
(66, 'genCoders', '', '', 'scmiitmcs@gmail.com', 'sha1$872f3$f8970e228504311394a80ddb6a523d3885982ea0', 0, 1, 0, '2011-09-20 08:54:14', '2011-09-20 08:54:06'),
(67, 'archi', '', '', 'mishi4a3@gmail.com', 'sha1$dbf00$60a047e4e5303e0d71e5c8b402ddc470bd29f3bb', 0, 1, 0, '2011-09-20 14:23:27', '2011-09-20 14:23:27'),
(68, 'ront', '', '', 'nishaanth08@gmail.com', 'sha1$494f3$ac1f2239d5b11d7d50eae8047abd29d48d835ac7', 0, 1, 0, '2011-09-23 13:23:30', '2011-09-20 21:44:42'),
(69, 'sasuke', '', '', 'psaibhushan@ymail.com', 'sha1$bbc1f$2e59f1056b569eff326b6166915b762affb33083', 0, 1, 0, '2011-09-21 08:08:20', '2011-09-20 21:38:12'),
(70, 'TheGreatMind', '', '', 'vibhudost@gmail.com', 'sha1$fabcb$fca269e9dd2ba82d42bb8f221711c8432debbe88', 0, 1, 0, '2011-09-21 15:06:21', '2011-09-21 09:39:57'),
(71, 'prashantkumar', '', '', 'pra088@gmail.com', 'sha1$0ae38$5f7455961f73ede62750ffd38523777ff9004742', 0, 1, 0, '2011-09-20 23:31:45', '2011-09-20 23:29:09'),
(72, 'abhi', '', '', 'abhison.003@gmail.com', 'sha1$0774c$f2da406d06c5742cb6b483e27055f756995d3ce8', 0, 1, 0, '2011-09-20 23:37:25', '2011-09-21 10:06:36'),
(73, 'naren_2011', '', '', '786.narendra@gmail.com', 'sha1$58faa$01bd50afa66619e8d64251e445b9d73aa26fc840', 0, 1, 0, '2011-09-21 20:59:51', '2011-09-20 23:38:28'),
(74, 'Natsu', '', '', 'annapareddyjanardhanreddy@gmail.com', 'sha1$5140b$d06fb2250eeb522b4781884702b8c32166d2dee4', 0, 1, 0, '2011-09-21 21:20:04', '2011-09-21 14:56:04'),
(75, 'thebrain', '', '', 'aalok.acceler@gmail.com', 'sha1$47dfe$59626d4be0cdb97b3db43980c850eeea64c6a3ec', 0, 1, 0, '2011-09-21 15:16:27', '2011-09-21 15:16:15'),
(76, 'INFERNO', '', '', 'panks@live.com', 'sha1$61755$3e300e971a92536322b400d2a8efab6912272f14', 0, 1, 0, '2011-09-21 15:46:35', '2011-09-21 15:46:25'),
(77, 'Deccan', '', '', 'vipra.dwivedi@gmail.com', 'sha1$54519$a0b3923314436c6f523d1af451eb52b9ff7b292d', 0, 1, 0, '2011-09-21 18:53:56', '2011-09-21 18:53:47'),
(78, 'pratik772845', '', '', 'pillu_gaurav@live.in', 'sha1$655f6$b42f9500407f91a8e6d5a9b94bdbaa459fa65f5f', 0, 1, 0, '2011-09-21 20:14:49', '2011-09-21 20:14:38'),
(79, '5ive', '', '', 'ravi0185@gmail.com', 'sha1$a6e61$fd81b6147bc72381605d564cb8ce1d26fdaef7c8', 0, 1, 0, '2011-09-21 20:51:50', '2011-09-21 20:50:49');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
