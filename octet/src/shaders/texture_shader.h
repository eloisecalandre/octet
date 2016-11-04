////////////////////////////////////////////////////////////////////////////////
//
// (C) Andy Thomason 2012-2014
//
// Modular Framework for OpenGLES2 rendering on multiple platforms.
//
// Single texture shader with no lighting

namespace octet { namespace shaders {
  class texture_shader : public shader {
    // indices to use with glUniform*()

    // index for model space to projection space matrix
    GLuint modelToProjectionIndex_;

    // index for texture sampler
    GLuint samplerIndex_;
	// ELOISE and MATTHEW creating a flag, the flat is the GLunit
	GLuint colourIndex_;
	// GLuint cakeIndex_;
  public:
    void init() {
      // this is the vertex shader.
      // it is called for each corner of each triangle
      // it inputs pos and uv from each corner
      // it outputs gl_Position and uv_ to the rasterizer
      const char vertex_shader[] = SHADER_STR(
        varying vec2 uv_;

        attribute vec4 pos;
        attribute vec2 uv;

        uniform mat4 modelToProjection;

        void main() { gl_Position = modelToProjection * pos; uv_ = uv; }
      );

      // this is the fragment shader
      // after the rasterizer breaks the triangle into fragments
      // this is called for every fragment
      // it outputs gl_FragColor, the color of the pixel and inputs uv_
      const char fragment_shader[] = SHADER_STR(
        varying vec2 uv_;
        uniform sampler2D sampler;
		// ELOISE creating uniform colour with support of Matthew Duddington
		// ELOISE and MATTHEW introducing the new uniform and declaring its type
		uniform vec4 colour;
		// uniform int cake;
		void main() {
			gl_FragColor = texture2D(sampler, uv_) *colour; 
		}
      );
    
      // use the common shader code to compile and link the shaders
      // the result is a shader program
      shader::init(vertex_shader, fragment_shader);

      // extract the indices of the uniforms to use later
	  // ELOISE and MATTHEW giving uniform location and attaching to the flag
      modelToProjectionIndex_ = glGetUniformLocation(program(), "modelToProjection");
      samplerIndex_ = glGetUniformLocation(program(), "sampler");
	  colourIndex_ = glGetUniformLocation(program(), "colour");
	  // cakeIndex_ = glGetUniformLocation(program(), "cake");
    }

    void render(const mat4t &modelToProjection, int sampler) {
      // tell openGL to use the program
      shader::render();

	  //ELOISE and MATTHEW transfering the original to the uniform
	  float colourArray[4] = { 0.3, 0.4, 0.8, 1 };
	  glUniform4fv(colourIndex_, 1, colourArray);
	 // glUniformi(cakeIndex_, )

      // customize the program with uniforms
      glUniform1i(samplerIndex_, sampler);
      glUniformMatrix4fv(modelToProjectionIndex_, 1, GL_FALSE, modelToProjection.get());
    }
  };
}}
