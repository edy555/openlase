require 'openlase_api'

module OpenLASE
  RENDER_GRAYSCALE = 1
  RENDER_NOREORDER = 2
  RENDER_NOREVERSE = 4

  LINESTRIP = 0
  BEZIERSTRIP = 1
  POINTS = 2

  C_RED   = 0xff0000
  C_GREEN = 0x00ff00
  C_BLUE  = 0x0000ff
  C_WHITE = 0xffffff
  C_BLACK = 0x000000

  def C_GREY(x)
    0x010101 * x.to_i
  end

  class RenderParams < Object
    attr_accessor :rate
    attr_accessor :on_speed
    attr_accessor :off_speed
    attr_accessor :start_wait
    attr_accessor :start_dwell
    attr_accessor :curve_dwell
    attr_accessor :corner_dwell
    attr_accessor :end_dwell
    attr_accessor :end_wait
    attr_accessor :curve_angle
    attr_accessor :flatness
    attr_accessor :snap
    attr_accessor :render_flags
    attr_accessor :min_length
    attr_accessor :max_framelen

    def initialize
      @rate = 48000
      @on_speed = 2.0/100.0
      @off_speed = 2.0/20.0
      @start_wait = 8
      @start_dwell = 3
      @curve_dwell = 0
      @corner_dwell = 8
      @end_dwell = 3
      @end_wait = 7
      @curve_angle = Math.cos(Math::PI*30/180)
      @flatness = 1
      @snap = 1/100000.0
      @render_flags = RENDER_GRAYSCALE
      @min_length = 0
      @max_framelen = 0
    end
  end

end
