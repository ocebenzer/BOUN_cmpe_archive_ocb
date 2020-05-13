public class OCB2017400048 {
	public static void CocktailTop(int size, int pos) {
		for (int j=1; j<=pos; j++) {
			for (int k=1; k<j; k++) {
				System.out.print(" ");
			}
			System.out.println("o");
		}		
	}
	public static void CocktailBottom(int size, int pos) {	
		for (int j=1; j<=size; j++) {
			System.out.print(" ");
		}
		System.out.println("--");
		for(int j=1; j<=size; j++){
			for (int k=1; k<=size; k++) {
				System.out.print(" ");
			}
			System.out.println("||");
		}
	}
	public static void Cocktail(int size, int pos) {
		for (int i=0; i<=size + 1 - ((pos+1) /2); i++) {
			CocktailTop(size,pos);
			//Middle Part starts here
			for (int j=1; j<=size; j++) {
				for (int k=1; k<j; k++) {
					System.out.print(" ");
				}
				System.out.print("\\");
				if (j > i) {
					for(int k = j; k<=2*size-j+1; k++){
						System.out.print("*");
					}
				}
				else {
					for(int k=j; k<=2*size-j+1; k++) {
						if(pos == k-j+1) {
							System.out.print("o");
						}
						else {
							System.out.print(" ");
						}
					}
				}
				System.out.println("/");
			}
			//Middle part ends here
			CocktailBottom(size,pos);
		}
	}
	public static void main(String[] args){
		int glassSize = Integer.parseInt(args[0]);
		int strawPos  = Integer.parseInt(args[1]);
		Cocktail(glassSize, strawPos);
		}
}