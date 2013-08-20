#version 120
uniform sampler2D texture;

void main(){

    vec4 targetColor = vec4(1.0, 1.0, 1.0, 1.0);
	
    vec2 pos = gl_TexCoord[0].xy;
    vec4 color = texture2D(texture, pos);
    
	if( all( equal(gl_Color, targetColor) ) ){
		gl_FragColor.rgb = color.rgb;
        gl_FragColor.a = 0.5;
    }else{
		gl_FragColor = color;
	}	
}