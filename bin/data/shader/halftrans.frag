#version 120
uniform sampler2D tex0;

void main(){

    vec4 targetColor = vec4(0.9, 0.9, 0.9, 0.9);
	
    vec4 color = texture2D(tex0, gl_TexCoord[0].xy);
    
	if( all( greaterThanEqual(color, targetColor) ) ){
		gl_FragColor.rgb = color.rgb;
        gl_FragColor.a = 0.5;
    }else{
		gl_FragColor = color;
	}	
}