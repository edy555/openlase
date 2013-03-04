#         OpenLase - a realtime laser graphics toolkit
#
# Copyright (C) 2009-2011 Hector Martin "marcan" <hector@marcansoft.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 or version 3.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
#

include_directories (${CMAKE_SOURCE_DIR}/include)
link_directories (${CMAKE_BINARY_DIR}/libol)
include_directories (${JACK_INCLUDE_DIR})

add_executable(openlase-circlescope circlescope.c)
target_link_libraries(openlase-circlescope ${JACK_LIBRARIES} m)
install (TARGETS openlase-circlescope RUNTIME DESTINATION bin)

add_executable(openlase-scope scope.c)
target_link_libraries(openlase-scope ${JACK_LIBRARIES} m)
install(TARGETS openlase-scope RUNTIME DESTINATION bin)

add_executable(openlase-simple simple.c)
target_link_libraries(openlase-simple openlase)
install (TARGETS openlase-simple RUNTIME DESTINATION bin)

if(NOT APPLE)
  add_executable(openlase-pong pong.c)
  target_link_libraries(openlase-pong openlase)
  install (TARGETS openlase-pong RUNTIME DESTINATION bin)
endif()

if(ALSA_FOUND)
  add_executable(openlase-midiview midiview.c)
  target_link_libraries(openlase-midiview openlase ${ALSA_LIBRARIES})
  install (TARGETS openlase-midiview RUNTIME DESTINATION bin)
else()
  message(STATUS "Will NOT build midiview (ALSA missing)")
endif()

add_executable(openlase-harp harp.c)
target_link_libraries(openlase-harp openlase)
install (TARGETS openlase-harp RUNTIME DESTINATION bin)

add_subdirectory(27c3_slides)
