class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> qp;
        sort(deck.begin(),deck.end()); 
        for(int i = deck.size()-1;i>=0;i--){
            if(!qp.empty()){ 
                qp.push(qp.front()); 
                qp.pop();
            }
            qp.push(deck[i]); 
        }
        for(int i = deck.size()-1;i>=0;i--){
            deck[i] = qp.front(); 
            qp.pop();
        }
        return deck;
    }
};