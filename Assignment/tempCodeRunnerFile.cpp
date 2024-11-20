
            vector<vector<Items>> layer;
            for (int j = 0; j <= locationY; j++) {
                vector<Items> row;
                for (int k = 0; k <= locationZ; k++) {
                    row.push_back(Items());
                }
                layer.push_back(row);
            }
            inventory.push_back(layer);
        }
    }