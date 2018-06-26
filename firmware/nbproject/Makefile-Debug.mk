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
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/App/alarms.o \
	${OBJECTDIR}/App/app.o \
	${OBJECTDIR}/App/status_bar/status_bar.o \
	${OBJECTDIR}/hardware.o \
	${OBJECTDIR}/kernel/drivers/beep_simulator.o \
	${OBJECTDIR}/kernel/drivers/cpu_control.o \
	${OBJECTDIR}/kernel/drivers/keyboard.o \
	${OBJECTDIR}/kernel/drivers/lcd_simulator.o \
	${OBJECTDIR}/kernel/drivers/real_time_clock.o \
	${OBJECTDIR}/kernel/fonts/alfanum_6.o \
	${OBJECTDIR}/kernel/fonts/alfanum_8.o \
	${OBJECTDIR}/kernel/fonts/numeric_16.o \
	${OBJECTDIR}/kernel/fonts/numeric_24.o \
	${OBJECTDIR}/kernel/kernel.o \
	${OBJECTDIR}/kernel/screen/screen.o \
	${OBJECTDIR}/kernel/settings/keyboard.o \
	${OBJECTDIR}/kernel/settings/screens.o \
	${OBJECTDIR}/kernel/settings/std.o \
	${OBJECTDIR}/kernel/settings/upp.o \
	${OBJECTDIR}/kernel/settings/util.o \
	${OBJECTDIR}/kernel/std.o \
	${OBJECTDIR}/kernel/upp/upp.o \
	${OBJECTDIR}/kernel/util.o \
	${OBJECTDIR}/language/language.o \
	${OBJECTDIR}/language/pt_br.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/screens/alarms.o \
	${OBJECTDIR}/screens/alarms_ringing.o \
	${OBJECTDIR}/screens/alarms_settings.o \
	${OBJECTDIR}/screens/calendar.o \
	${OBJECTDIR}/screens/calendar_events.o \
	${OBJECTDIR}/screens/main.o \
	${OBJECTDIR}/screens/menu.o \
	${OBJECTDIR}/screens/settings.o \
	${OBJECTDIR}/screens/settings_date_hour.o \
	${OBJECTDIR}/screens/status.o \
	${OBJECTDIR}/screens/stopwatch.o


# C Compiler Flags
CFLAGS=-std=c99

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/firmware

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/firmware: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/firmware ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/App/alarms.o: App/alarms.c
	${MKDIR} -p ${OBJECTDIR}/App
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/App/alarms.o App/alarms.c

${OBJECTDIR}/App/app.o: App/app.c
	${MKDIR} -p ${OBJECTDIR}/App
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/App/app.o App/app.c

${OBJECTDIR}/App/status_bar/status_bar.o: App/status_bar/status_bar.c
	${MKDIR} -p ${OBJECTDIR}/App/status_bar
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/App/status_bar/status_bar.o App/status_bar/status_bar.c

${OBJECTDIR}/hardware.o: hardware.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hardware.o hardware.c

${OBJECTDIR}/kernel/drivers/beep_simulator.o: kernel/drivers/beep_simulator.c
	${MKDIR} -p ${OBJECTDIR}/kernel/drivers
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/drivers/beep_simulator.o kernel/drivers/beep_simulator.c

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

${OBJECTDIR}/kernel/fonts/alfanum_6.o: kernel/fonts/alfanum_6.c
	${MKDIR} -p ${OBJECTDIR}/kernel/fonts
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/fonts/alfanum_6.o kernel/fonts/alfanum_6.c

${OBJECTDIR}/kernel/fonts/alfanum_8.o: kernel/fonts/alfanum_8.c
	${MKDIR} -p ${OBJECTDIR}/kernel/fonts
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/fonts/alfanum_8.o kernel/fonts/alfanum_8.c

${OBJECTDIR}/kernel/fonts/numeric_16.o: kernel/fonts/numeric_16.c
	${MKDIR} -p ${OBJECTDIR}/kernel/fonts
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/fonts/numeric_16.o kernel/fonts/numeric_16.c

${OBJECTDIR}/kernel/fonts/numeric_24.o: kernel/fonts/numeric_24.c
	${MKDIR} -p ${OBJECTDIR}/kernel/fonts
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/fonts/numeric_24.o kernel/fonts/numeric_24.c

${OBJECTDIR}/kernel/kernel.o: kernel/kernel.c
	${MKDIR} -p ${OBJECTDIR}/kernel
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/kernel.o kernel/kernel.c

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

${OBJECTDIR}/kernel/std.o: kernel/std.c
	${MKDIR} -p ${OBJECTDIR}/kernel
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/std.o kernel/std.c

${OBJECTDIR}/kernel/upp/upp.o: kernel/upp/upp.c
	${MKDIR} -p ${OBJECTDIR}/kernel/upp
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/upp/upp.o kernel/upp/upp.c

${OBJECTDIR}/kernel/util.o: kernel/util.c
	${MKDIR} -p ${OBJECTDIR}/kernel
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/kernel/util.o kernel/util.c

${OBJECTDIR}/language/language.o: language/language.c
	${MKDIR} -p ${OBJECTDIR}/language
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/language/language.o language/language.c

${OBJECTDIR}/language/pt_br.o: language/pt_br.c
	${MKDIR} -p ${OBJECTDIR}/language
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/language/pt_br.o language/pt_br.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/screens/alarms.o: screens/alarms.c
	${MKDIR} -p ${OBJECTDIR}/screens
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/screens/alarms.o screens/alarms.c

${OBJECTDIR}/screens/alarms_ringing.o: screens/alarms_ringing.c
	${MKDIR} -p ${OBJECTDIR}/screens
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/screens/alarms_ringing.o screens/alarms_ringing.c

${OBJECTDIR}/screens/alarms_settings.o: screens/alarms_settings.c
	${MKDIR} -p ${OBJECTDIR}/screens
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/screens/alarms_settings.o screens/alarms_settings.c

${OBJECTDIR}/screens/calendar.o: screens/calendar.c
	${MKDIR} -p ${OBJECTDIR}/screens
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/screens/calendar.o screens/calendar.c

${OBJECTDIR}/screens/calendar_events.o: screens/calendar_events.c
	${MKDIR} -p ${OBJECTDIR}/screens
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/screens/calendar_events.o screens/calendar_events.c

${OBJECTDIR}/screens/main.o: screens/main.c
	${MKDIR} -p ${OBJECTDIR}/screens
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/screens/main.o screens/main.c

${OBJECTDIR}/screens/menu.o: screens/menu.c
	${MKDIR} -p ${OBJECTDIR}/screens
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/screens/menu.o screens/menu.c

${OBJECTDIR}/screens/settings.o: screens/settings.c
	${MKDIR} -p ${OBJECTDIR}/screens
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/screens/settings.o screens/settings.c

${OBJECTDIR}/screens/settings_date_hour.o: screens/settings_date_hour.c
	${MKDIR} -p ${OBJECTDIR}/screens
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/screens/settings_date_hour.o screens/settings_date_hour.c

${OBJECTDIR}/screens/status.o: screens/status.c
	${MKDIR} -p ${OBJECTDIR}/screens
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/screens/status.o screens/status.c

${OBJECTDIR}/screens/stopwatch.o: screens/stopwatch.c
	${MKDIR} -p ${OBJECTDIR}/screens
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/screens/stopwatch.o screens/stopwatch.c

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
