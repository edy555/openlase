#!/usr/bin/env ruby -w
require 'openlase'

ol=OpenLASE

p ol.init(3, 30000)

params = OpenLASE::RenderParams.new
ol.setRenderParams(params)

pi = Math::PI
time = 0
frames = 0

while true do
  ol.loadIdentity3
  ol.loadIdentity

  #font = ol.getDefaultFont
  #s = "Hi!"
  #w = ol.getStringWidth(font, 0.2, s)
  #ol.drawString(font, (-w/2,0.1), 0.2, ol.C_WHITE, s)

  ol.perspective(60, 1, 1, 100)
  ol.translate3(0, 0, -3)

  (0..1).each {|i|
    ol.scale3(0.6, 0.6, 0.6)
    ol.rotate3Z(time * pi * 0.1)
    ol.rotate3X(time * pi * 0.8)
    ol.rotate3Y(time * pi * 0.73)

    ol.begin(ol::LINESTRIP)
    ol.vertex3(-1, -1, -1, ol::C_WHITE)
    ol.vertex3( 1, -1, -1, ol::C_WHITE)
    ol.vertex3( 1,  1, -1, ol::C_WHITE)
    ol.vertex3(-1,  1, -1, ol::C_WHITE)
    ol.vertex3(-1, -1, -1, ol::C_WHITE)
    ol.vertex3(-1, -1,  1, ol::C_WHITE)
    ol.end

    ol.begin(ol::LINESTRIP);
    ol.vertex3( 1,  1,  1, ol::C_WHITE)
    ol.vertex3(-1,  1,  1, ol::C_WHITE)
    ol.vertex3(-1, -1,  1, ol::C_WHITE)
    ol.vertex3( 1, -1,  1, ol::C_WHITE)
    ol.vertex3( 1,  1,  1, ol::C_WHITE)
    ol.vertex3( 1,  1, -1, ol::C_WHITE)
    ol.end

    ol.begin(ol::LINESTRIP)
    ol.vertex3( 1, -1, -1, ol::C_WHITE)
    ol.vertex3( 1, -1,  1, ol::C_WHITE)
    ol.end

    ol.begin(ol::LINESTRIP)
    ol.vertex3(-1,  1,  1, ol::C_WHITE)
    ol.vertex3(-1,  1, -1, ol::C_WHITE)
    ol.end

	ftime = ol.renderFrame(60)
	frames += 1
	time += ftime
	print "Frame time: #{ftime}, FPS:#{frames/time}\n"
  }
end

ol.shutdown
