cmake_minimum_required(VERSION 3.27)
project(TechSolveHR)

set(CMAKE_CXX_STANDARD 14)

include_directories(TechSolveHR)

add_executable(TechSolveHR
        TechSolveHR/AdminUser.cpp
        TechSolveHR/AdminUser.h
        TechSolveHR/AttendanceData.cpp
        TechSolveHR/AttendanceData.h
        TechSolveHR/boolinq.h
        TechSolveHR/Console.h
        TechSolveHR/EditableData.cpp
        TechSolveHR/EditableData.h
        TechSolveHR/EmergencyData.cpp
        TechSolveHR/EmergencyData.h
        TechSolveHR/Employee.cpp
        TechSolveHR/Employee.h
        TechSolveHR/json.hpp
        TechSolveHR/LeaveData.cpp
        TechSolveHR/LeaveData.h
        TechSolveHR/LeaveRecord.cpp
        TechSolveHR/LeaveRecord.h
        TechSolveHR/OvertimeData.cpp
        TechSolveHR/OvertimeData.h
        TechSolveHR/PerformanceData.cpp
        TechSolveHR/PerformanceData.h
        TechSolveHR/PerformanceReview.cpp
        TechSolveHR/PerformanceReview.h
        TechSolveHR/PersonalData.cpp
        TechSolveHR/PersonalData.h
        TechSolveHR/TechSolveHR.cpp
        TechSolveHR/User.cpp
        TechSolveHR/User.h
        TechSolveHR/WorkData.cpp
        TechSolveHR/WorkData.h)
