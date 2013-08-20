#version 120
uniform sampler2D texture;

void main(){

    vec4 targetColor = vec4(1., 1.0, 1.0, 1.0);
	
    vec2 pos = gl_TexCoord[0].xy;
    vec4 color = texture2D(texture, pos);
    
	if( all( equal(color, targetColor) ) ){
		gl_FragColor = vec4(color.r,color.g,color.b, .5);
    }else{
		gl_FragColor = color;
	}
	
}