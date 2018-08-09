
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class SplitImage {

	public static void main(String[] args) {
	try {
			
		//Provide numer of rows and column
		int row = 1;
		int col = 3;
		
		BufferedImage originalImgage = ImageIO.read(new File("p.jpg"));
		
		//total width and total height of an image
		int tWidth = originalImgage.getWidth();
		int tHeight = originalImgage.getHeight();
		
		//width and height of each piece
		int eWidth = tWidth / col;
		int eHeight = tHeight / row;

		int x = 0;
		int y = 0;

		for (int i = 0; i < row; i++) {
			y = 0;
			for (int j = 0; j < col; j++) {
				try {				
					BufferedImage SubImgage = originalImgage.getSubimage(y, x, eWidth, eHeight);
					File outputfile = new File("p"+i+j+".jpg");
					ImageIO.write(SubImgage, "jpg", outputfile);
					
					y += eWidth;
					
				} catch (Exception e) {
					e.printStackTrace();
				}
			}

			x += eHeight;
		}

	} catch (IOException e) {
		e.printStackTrace();
	}
	
	}
}
