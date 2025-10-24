#version 150

uniform vec2 u_resolution;
uniform sampler2DRect tex0;
uniform float u_exp;
uniform float u_rot;

out vec4 fragColor;
in vec2 vTexCoord;

//[-0.5, 0.5]のuvを受け取る
vec2 distortImage(float r, float t, float exp) {
  r = pow(r, exp);
  return r * vec2(cos(t), sin(t));
}

//rotSt -> stlength
mat2 rotateImage(float r, float rotSt) {
  float angle = r / 0.5 * 3.14 * rotSt;
  angle = -angle;
  return mat2(cos(angle), -sin(angle), sin(angle), cos(angle));
}

vec2 rotateFishEye(vec2 uv, float exp, float rotSt) {
  vec2 center = vec2(0.5, 0.5);
  uv -= center;

  float r = length(uv);
  float t = atan(uv.y, uv.x);
  uv = distortImage(r, t, exp);

  mat2 rot = rotateImage(r, rotSt);
  uv = rot * uv;

  uv += center;
  return uv;
}

void main() {
  vec2 uv = vTexCoord / u_resolution;
  uv = rotateFishEye(uv, u_exp, u_rot);

  vec2 texCoord = uv * u_resolution;
  vec4 color = texture(tex0, texCoord);

  float luminance = dot(color.rgb, vec3(0.2126, 0.7152, 0.0722));
  float grayColor = smoothstep(0.03, 0.5, luminance);

  fragColor = vec4(vec3(grayColor), 1.0);
}
