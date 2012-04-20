#include <ruby.h>
#include "libol.h"

VALUE mod_ol;

static VALUE
ol_init(VALUE self, VALUE buffer_count, VALUE max_points)
{
  int bc = NUM2INT(buffer_count);
  int mp = NUM2INT(max_points);
  int n = 0;

  n = olInit(bc, mp);
  return INT2FIX(n);
}

static VALUE
ol_setRenderParams(VALUE self, VALUE v)
{
  OLRenderParams params;
  params.rate = NUM2INT(rb_iv_get(v, "@rate"));
  params.on_speed = NUM2DBL(rb_iv_get(v, "@on_speed"));
  params.off_speed = NUM2DBL(rb_iv_get(v, "@off_speed"));
  params.start_dwell = NUM2INT(rb_iv_get(v, "@start_dwell"));
  params.curve_dwell = NUM2INT(rb_iv_get(v, "@curve_dwell"));
  params.corner_dwell = NUM2INT(rb_iv_get(v, "@corner_dwell"));
  params.end_dwell = NUM2INT(rb_iv_get(v, "@end_dwell"));
  params.end_wait = NUM2INT(rb_iv_get(v, "@end_wait"));
  params.curve_angle = NUM2DBL(rb_iv_get(v, "@curve_angle"));
  params.flatness = NUM2DBL(rb_iv_get(v, "@flatness"));
  params.snap = NUM2DBL(rb_iv_get(v, "@snap"));
  params.render_flags = NUM2INT(rb_iv_get(v, "@render_flags"));
  params.min_length = NUM2INT(rb_iv_get(v, "@min_length"));
  params.max_framelen = NUM2INT(rb_iv_get(v, "@max_framelen"));
  olSetRenderParams(&params);
}

static VALUE
ol_loadIdentity()
{
  olLoadIdentity();
  return Qnil;
}

static VALUE
ol_pushMatrix()
{
  olPushMatrix();
  return Qnil;
}

static VALUE
ol_popMatrix()
{
  olPopMatrix();
  return Qnil;
}

static VALUE
ol_multMatrix(VALUE self, VALUE v)
{
  float m[9];
  int i;
  for (i = 0; i < 9; i++)
    m[i] = NUM2DBL(rb_ary_entry(v, i));
  olMultMatrix(m);
  return Qnil;
}

static VALUE
ol_rotate(VALUE self, VALUE v)
{
  olRotate(NUM2DBL(v));
  return Qnil;
}

static VALUE
ol_translate(VALUE self, VALUE x, VALUE y)
{
  olTranslate(NUM2DBL(x), NUM2DBL(y));
  return Qnil;
}

static VALUE
ol_scale(VALUE self, VALUE sx, VALUE sy)
{
  olScale(NUM2DBL(sx), NUM2DBL(sy));
  return Qnil;
}

static VALUE
ol_loadIdentity3()
{
  olLoadIdentity3();
  return Qnil;
}

static VALUE
ol_pushMatrix3()
{
  olPushMatrix3();
  return Qnil;
}

static VALUE
ol_popMatrix3()
{
  olPopMatrix3();
  return Qnil;
}


static VALUE
ol_multMatrix3(VALUE self, VALUE v)
{
  float m[16];
  int i;
  for (i = 0; i < 16; i++)
    m[i] = NUM2DBL(rb_ary_entry(v, i));
  olMultMatrix3(m);
  return Qnil;
}

static VALUE
ol_rotate3X(VALUE self, VALUE v)
{
  olRotate3X(NUM2DBL(v));
  return Qnil;
}

static VALUE
ol_rotate3Y(VALUE self, VALUE v)
{
  olRotate3Y(NUM2DBL(v));
  return Qnil;
}

static VALUE
ol_rotate3Z(VALUE self, VALUE v)
{
  olRotate3Z(NUM2DBL(v));
  return Qnil;
}

static VALUE
ol_translate3(VALUE self, VALUE x, VALUE y, VALUE z)
{
  olTranslate3(NUM2DBL(x), NUM2DBL(y), NUM2DBL(z));
  return Qnil;
}

static VALUE
ol_scale3(VALUE self, VALUE sx, VALUE sy, VALUE sz)
{
  olScale3(NUM2DBL(sx), NUM2DBL(sy), NUM2DBL(sz));
  return Qnil;
}

static VALUE
ol_perspective(VALUE self, VALUE fovy, VALUE aspect, VALUE zNear, VALUE zFar)
{
  olPerspective(NUM2DBL(fovy), NUM2DBL(aspect), NUM2DBL(zNear), NUM2DBL(zFar));
  return Qnil;
}

static VALUE
ol_begin(VALUE self, VALUE prim)
{
  olBegin(NUM2INT(prim));
  return Qnil;
}

static VALUE
ol_vertex(VALUE self, VALUE x, VALUE y, VALUE color)
{
  olVertex(NUM2DBL(x), NUM2DBL(y), NUM2INT(color));
  return Qnil;
}

static VALUE
ol_vertex3(VALUE self, VALUE x, VALUE y, VALUE z, VALUE color)
{
  olVertex3(NUM2DBL(x), NUM2DBL(y), NUM2DBL(z), NUM2INT(color));
  return Qnil;
}

static VALUE
ol_end(VALUE self)
{
  olEnd();
  return Qnil;
}

static VALUE
ol_shutdown(VALUE self)
{
  olShutdown();
  return Qnil;
}

static VALUE
ol_renderFrame(VALUE self, VALUE max_fps)
{
  float f = olRenderFrame(NUM2INT(max_fps));
  return rb_float_new(f);
}



int Init_openlase_api(void)
{
  mod_ol = rb_define_module("OpenLASE");

  rb_define_module_function(mod_ol, "init", ol_init, 2);
  rb_define_module_function(mod_ol, "setRenderParams", ol_setRenderParams, 1);

  rb_define_module_function(mod_ol, "loadIdentity", ol_loadIdentity, 0);
  rb_define_module_function(mod_ol, "pushMatrix", ol_pushMatrix, 0);
  rb_define_module_function(mod_ol, "popMatrix", ol_popMatrix, 0);

  rb_define_module_function(mod_ol, "multMatrix", ol_multMatrix, 1);
  rb_define_module_function(mod_ol, "rotate", ol_rotate, 1);
  rb_define_module_function(mod_ol, "translate", ol_translate, 2);
  rb_define_module_function(mod_ol, "scale", ol_scale, 2);

  rb_define_module_function(mod_ol, "loadIdentity3", ol_loadIdentity3, 0);
  rb_define_module_function(mod_ol, "pushMatrix3", ol_pushMatrix3, 0);
  rb_define_module_function(mod_ol, "popMatrix3", ol_popMatrix3, 0);

  rb_define_module_function(mod_ol, "multMatrix3", ol_multMatrix3, 1);
  rb_define_module_function(mod_ol, "rotate3X", ol_rotate3X, 1);
  rb_define_module_function(mod_ol, "rotate3Y", ol_rotate3Y, 1);
  rb_define_module_function(mod_ol, "rotate3Z", ol_rotate3Z, 1);
  rb_define_module_function(mod_ol, "translate3", ol_translate3, 3);
  rb_define_module_function(mod_ol, "scale3", ol_scale3, 3);

  rb_define_module_function(mod_ol, "perspective", ol_perspective, 4);
  rb_define_module_function(mod_ol, "begin", ol_begin, 1);
  rb_define_module_function(mod_ol, "vertex", ol_vertex, 3);
  rb_define_module_function(mod_ol, "vertex3", ol_vertex3, 4);
  rb_define_module_function(mod_ol, "end", ol_end, 0);
  rb_define_module_function(mod_ol, "shutdown", ol_shutdown, 0);
  rb_define_module_function(mod_ol, "renderFrame", ol_renderFrame, 1);
}
