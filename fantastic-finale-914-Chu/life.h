#pragma once
class Life {
	
	private:
		
		int life = 10;

	public:
		Life();
        ~Life();
        void Update(bool hurt);
        void Draw();
        int GetCurrentLife();
		
		

};
