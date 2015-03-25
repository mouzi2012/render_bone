SHELL       = /bin/sh
CXX = g++
CXXFLAGS = -g -Wall
CPPFLAGS = -I./ -Iglfw/include 

VPATH =RenderBone:FbxReader

outputDir = debug/
objects :=  $(patsubst %.cpp,%.o,$(wildcard RenderBone/*.cpp *.cpp))
objectsOut := $(addprefix $(outputDir),$(notdir $(objects)))
outputObj := test01

test : $(objectsOut)
	$(CXX) -o $(outputObj) $(objectsOut) -Lglfw/src -lglfw3 -lGLEW -lGL -lXrandr -lm -lXi


depend0 := %.cpp
$(objectsOut):$(outputDir)%.o:$(depend0)
	$(CXX) -c $(CPPFLAGS) $(CXXFLAGS) $< -o $(outputDir)$(@F) 

.PHONY : clean	
clean : 
	-rm $(outputDir)*

#echotest :
#	@echo $(objects)
#	@echo $(objectsOut)
#	@echo %
#	@echo $$
#	@echo $(depend)

