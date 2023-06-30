class Altset {
    int len;
    char *str = new char[len + 1];
public:
    Altset();
    ~Altset();

    Altset(char *data, int len);
	Altset& operator = (const Altset &altset);
    Altset& operator = (Altset &&altset);

    void inverse(int index); //op=0
    void append(int value);  //op=1
    bool get(int index) const;  //op=4
    bool empty() const;
    int count() const;
};
