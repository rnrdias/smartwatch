#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW_TDM-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/hardware.o \
	${OBJECTDIR}/kernel/drivers/cpu_control.o \
	${OBJECTDIR}/kernel/drivers/keyboard.o \
	${OBJECTDIR}/kernel/drivers/lcd_simulator.o \
	${OBJECTDIR}/kernel/drivers/real_time_clock.o \
	${OBJECTDIR}/kernel/screen/debug.o \
	${OBJECTDIR}/kernel/screen/notepad.o \
	${OBJECTDIR}/kernel/screen/screen.o \
	${OBJECTDIR}/kernel/settings/keyboard.o \
	${OBJECTDIR}/kernel/settings/screens.o \
	${OBJECTDIR}/kernel/settings/std.o \
	${OBJECTDIR}/kernel/settings/upp.o \
	${OBJECTDIR}/kernel/settings/util.o \
	${OBJECTDIR}/kernel/start.o \
	${OBJECTDIR}/kernel/std.o \
	${OBJECTDIR}/kernel/upp/fonte.o \
	${OBJECTDIR}/kernel/upp/upp.o \
	${OBJECTDIR}/kernel/util.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/firmware.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/firmware.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/firmware ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/hardware.o: hardware.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hardware.o hardware.c

${OBJECTDIR}/kernel/drivers/cpu_control.o: kernel/drivers/cpu_control.c
	${MKDIR} -p ${OBJECTDIR}/kernel/drivers
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/drivers/cpu_control.o kernel/drivers/cpu_control.c

${OBJECTDIR}/kernel/drivers/keyboard.o: kernel/drivers/keyboard.c
	${MKDIR} -p ${OBJECTDIR}/kernel/drivers
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/drivers/keyboard.o kernel/drivers/keyboard.c

${OBJECTDIR}/kernel/drivers/lcd_simulator.o: kernel/drivers/lcd_simulator.c
	${MKDIR} -p ${OBJECTDIR}/kernel/drivers
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/drivers/lcd_simulator.o kernel/drivers/lcd_simulator.c

${OBJECTDIR}/kernel/drivers/real_time_clock.o: kernel/drivers/real_time_clock.c
	${MKDIR} -p ${OBJECTDIR}/kernel/drivers
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/drivers/real_time_clock.o kernel/drivers/real_time_clock.c

${OBJECTDIR}/kernel/screen/debug.o: kernel/screen/debug.c
	${MKDIR} -p ${OBJECTDIR}/kernel/screen
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/screen/debug.o kernel/screen/debug.c

${OBJECTDIR}/kernel/screen/notepad.o: kernel/screen/notepad.c
	${MKDIR} -p ${OBJECTDIR}/kernel/screen
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/screen/notepad.o kernel/screen/notepad.c

${OBJECTDIR}/kernel/screen/screen.o: kernel/screen/screen.c
	${MKDIR} -p ${OBJECTDIR}/kernel/screen
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/screen/screen.o kernel/screen/screen.c

${OBJECTDIR}/kernel/settings/keyboard.o: kernel/settings/keyboard.c
	${MKDIR} -p ${OBJECTDIR}/kernel/settings
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/settings/keyboard.o kernel/settings/keyboard.c

${OBJECTDIR}/kernel/settings/screens.o: kernel/settings/screens.c
	${MKDIR} -p ${OBJECTDIR}/kernel/settings
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/settings/screens.o kernel/settings/screens.c

${OBJECTDIR}/kernel/settings/std.o: kernel/settings/std.c
	${MKDIR} -p ${OBJECTDIR}/kernel/settings
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/settings/std.o kernel/settings/std.c

${OBJECTDIR}/kernel/settings/upp.o: kernel/settings/upp.c
	${MKDIR} -p ${OBJECTDIR}/kernel/settings
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/settings/upp.o kernel/settings/upp.c

${OBJECTDIR}/kernel/settings/util.o: kernel/settings/util.c
	${MKDIR} -p ${OBJECTDIR}/kernel/settings
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/settings/util.o kernel/settings/util.c

${OBJECTDIR}/kernel/start.o: kernel/start.c
	${MKDIR} -p ${OBJECTDIR}/kernel
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/start.o kernel/start.c

${OBJECTDIR}/kernel/std.o: kernel/std.c
	${MKDIR} -p ${OBJECTDIR}/kernel
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/std.o kernel/std.c

${OBJECTDIR}/kernel/upp/fonte.o: kernel/upp/fonte.c
	${MKDIR} -p ${OBJECTDIR}/kernel/upp
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/upp/fonte.o kernel/upp/fonte.c

${OBJECTDIR}/kernel/upp/upp.o: kernel/upp/upp.c
	${MKDIR} -p ${OBJECTDIR}/kernel/upp
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/upp/upp.o kernel/upp/upp.c

${OBJECTDIR}/kernel/util.o: kernel/util.c
	${MKDIR} -p ${OBJECTDIR}/kernel
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/util.o kernel/util.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
