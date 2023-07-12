-- phpMyAdmin SQL Dump
-- version 4.9.2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Apr 08, 2020 at 11:48 AM
-- Server version: 10.4.11-MariaDB
-- PHP Version: 7.2.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `sms`
--

-- --------------------------------------------------------

--
-- Table structure for table `login`
--

CREATE TABLE `login` (
  `s_no` int(11) PRIMARY KEY NOT NULL,
  `name` varchar(50) NOT NULL,
  `email` varchar(250) NOT NULL,
  `password` varchar(250) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `login`
--

INSERT INTO `login` (`s_no`, `name`, `email`, `password`) VALUES
(1, 'Admin', 'admin@gmail.com', 'admin@123');

-- --------------------------------------------------------

--
-- Table structure for table `students`
--

CREATE TABLE `students` (
  `s_no` int(11) PRIMARY KEY NOT NULL,
  `roll_no` int(11) NOT NULL,
  `name` varchar(100) NOT NULL,
  `father_name` varchar(100) NOT NULL,
  `course` varchar(25) NOT NULL,
  `section` varchar(25) NOT NULL,
  `mobile` varchar(25) NOT NULL,
  `email` varchar(100) NOT NULL,
  `password` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `students`
--

INSERT INTO `students` (`s_no`, `roll_no`, `name`, `father_name`, `course`, `section`, `mobile`, `email`, `password`) VALUES
(1, 1001, 'Ayush Rawat', 'S.S Rawat', 'Btech CSE', 'AI & DS', '6598745121', 'ayush@gmail.com', 'ayush@123'),
(2, 1002, 'Saumya Deep Rawat', 'XYZ', 'Btech CSE', 'AI & DS', '1234567789', 'saumya@gmail.com', 'saumya@123'),
(3, 1003, 'Mohan', 'Sohan', 'Bsc', 'A', '2545874581', 'mohan@gmail.com', 'mohan@123'),
(4, 1003, 'Mohan', 'Sohan', 'Bsc', 'A', '2545874581', 'mohan@gmail.com', 'mohan@123');

-- --------------------------------------------------------

--
-- Table structure for table `teachers`
--

CREATE TABLE `teachers` (
  `s_no` int(11) PRIMARY KEY NOT NULL,
  `t_id` int(11) NOT NULL,
  `name` varchar(100) NOT NULL,
  `mobile` varchar(12) NOT NULL,
  `courses` varchar(250) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `teachers`
--

INSERT INTO `teachers` (`s_no`, `t_id`, `name`, `mobile`, `courses`) VALUES
(1, 101, 'Shivam Yadav', '5484654878', 'Physics, Maths'),
(2, 102, 'Gopal Sharma', '9878452484', 'English, Reasoning, Verbal'),
(103, 103, 'Rohit Sharma', '7887451254', 'Web Development, C++, Python');

--
-- Indexes for dumped tables
--

CREATE TABLE `marks` (
  `s_no` int(11) PRIMARY KEY NOT NULL,
  `Name` varchar(20),
  `Web Development` int(50),
  `Compiler Design` int(50),
  `Image Processing` int(50),
  `percentage` int(10)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- INSERT INTO `marks` (`s_no`,`Web Development`,`Complier Design`,`Image Processing`,`marks_obt`,`total_marks`,`percentage`) VALUES
-- (1,80,50,60,80,100),
-- (1,1,'Web Development',80,100),
-- (1,1,'Web Development',80,100),

--
-- Indexes for table `login`
-- --
-- ALTER TABLE `login`
--   ADD PRIMARY KEY (`s_no`);

--
-- Indexes for table `students`
--
-- ALTER TABLE `students`
--   ADD PRIMARY KEY (`s_no`);

--
-- Indexes for table `teachers`
--
-- ALTER TABLE `teachers`
--   ADD PRIMARY KEY (`s_no`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `login`
--
ALTER TABLE `login`
  MODIFY `s_no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `students`
--
ALTER TABLE `students`
  MODIFY `s_no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;

--
-- AUTO_INCREMENT for table `teachers`
--
ALTER TABLE `teachers`
  MODIFY `s_no` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=104;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
