export interface BuylistEntry {
  readonly cardName: string;
  readonly price: number;
  readonly purplemanaId: string;
  readonly scryfallId: string;
}

export function parseBuylistData(unparsedBuylistData: any): ReadonlyArray<BuylistEntry> {
  // TODO
  return [];
}
