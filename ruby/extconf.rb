require 'mkmf'

find_header("libol.h", "../include")
find_library("openlase", nil, "../libol")

if Config::CONFIG["target_os"] =~ /darwin/
  $objs = ["openlase.o"]
  #$libs += " -L../libol -lopenlase -ljack" 
end

if Config::CONFIG["target_os"] =~ /linux/
  $objs = ["openlase.o"]
end

if Config::CONFIG["target_os"] =~ /mswin/
  $objs = ["openlase.o"]
end

create_makefile('openlase_api')
